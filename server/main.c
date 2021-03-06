#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <avr/wdt.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define showDebugDataMain 0
#define sensorsCount 3

#include "main.h"
#include "slUart.h"
#include "slNRF24.h"
#include "slBME180Measure.h"
#include "slSPI.h"

#define LED (1 << PB0)
#define LED_TOG PORTB ^= LED


void clearData();

void setupTimer();

void setupInt0();

//server
void sensor11start();

void getDataFromSensor();

void sendingSensorDataViaUart();

uint8_t data[9];
uint8_t status;
struct MEASURE BME180measure = {0, 0, 0, 0, 11};
volatile uint8_t stage = 0;
//stage
volatile uint16_t counter = 0;
//counter for next mesure
volatile uint16_t counter2 = 0;
//counter for reset mesurements
volatile uint16_t counter3 = 0;
//counter for fail response form sensor
volatile uint8_t sensorNr = 0;
//nr of sensor from sensorsStrings
char sensorsStrings[sensorsCount][9] = {
    {'s', 't', 'a', 'r', 't', '-', 's', '2', '1'},
    {'s', 't', 'a', 'r', 't', '-', 's', '1', '1'},
    {'s', 't', 'a', 'r', 't', '-', 's', '1', '2'}
};
uint8_t sensorsAdresses[sensorsCount][1] = {
    {0x21},
    {0x11},
    {0x12}
};

int main(void) {
    //*
    slUART_SimpleTransmitInit();
    /*/
    slUART_Init();
    //*/
    slSPI_Init();
    slNRF24_IoInit();
    slNRF24_Init(*sensorsAdresses[0]);
    setupTimer();
    setupInt0();
    sei();
    stage = 1;
    slUART_WriteStringNl("\nStart server");
    _delay_ms(500);
    slNRF24_Reset();
    while (1) {
        switch (stage) {
        case 1:
            sensor11start();
            break;
        }
    }
    return 0;
}


void clearData() {
    for (uint8_t i = 0; i < 9; i++) {
        data[i] = 0;
    };
}

void setupTimer() {
    TCCR0B |= (1 << CS02) | (1 << CS00);//prescaler 1024
    TIMSK0 |= (1 << TOIE0);//przerwanie przy przepłnieniu timera0
}

void setupInt0() {
    DDRD &= ~(1 << DDD2);     // Clear the PD2 pin
    // PD2 (PCINT0 pin) is now an input
    PORTD |= (1 << PORTD2);    // turn On the Pull-up
    // PD2 is now an input with pull-up enabled
    EICRA |= (1 << ISC01);// INT0 falling edge    PD2
    EICRA &= ~(1 << ISC00);// INT0 falling edge PD2
    EIMSK |= (1 << INT0);     // Turns on INT0
}

uint8_t nextSensorNr() {
    sensorNr = sensorNr + 1;
    if (sensorNr > sensorsCount) {
        sensorNr = 1;
    }
    return sensorNr;
}

//server

//stage1
void sensor11start() {
    counter = 0;
    counter3 = 1;
    slNRF24_PowerDown();
    nextSensorNr();
    slNRF24_Reset();
    slNRF24_FlushTx();
    slNRF24_FlushRx();
    slUART_WriteString("S");
    slUART_LogHexNl(*sensorsAdresses[(sensorNr - 1)]);
    slNRF24_TxPowerUp(*sensorsAdresses[(sensorNr - 1)], sensorNr);
    slNRF24_TransmitPayload(&sensorsStrings[(sensorNr - 1)], 9);
    slNRF24_RxPowerUp(*sensorsAdresses[(sensorNr - 1)], sensorNr);
    slNRF24_FlushTx();
    slNRF24_FlushRx();
    slNRF24_Reset();
    clearData();
    stage = 0;//wait for interupt
}

//stage 3
void getDataFromSensor() {
    counter = 0;
    counter3 = 0;
    slNRF24_GetRegister(R_RX_PAYLOAD, data, 9);
}

//stage 4
void sendingSensorDataViaUart() {
    counter = 0;
    counter3 = 0;
    #if showDebugDataMain == 1
        slUART_WriteStringNl("server sendingSensorDataViaUart");
    #endif
    BME180measure = returnMEASUREFromBuffer(data);
    slUART_LogDecWithSign(BME180measure.temperature);
    slUART_WriteString("|");
    slUART_LogDec(BME180measure.humidity);
    slUART_WriteString("|");
    slUART_LogDecWithSign(BME180measure.pressure);
    slUART_WriteString("|");
    slUART_LogDecWithSign(BME180measure.voltage);
    slUART_WriteString("|");
    slUART_LogDec(BME180measure.sensorId);
    slUART_WriteStringNl("");
    if (sensorNr < sensorsCount) {
        stage = 1;
    } else {
        stage = 0;//all sensors wills be requested
    }
    clearData();
}

ISR(TIMER0_OVF_vect) {
    //co 0.01632sek.
    if (stage == 0) {
        counter = counter + 1;
        if (counter3 > 0) {
            counter3 = counter3 + 1;
        }
    } else {
        counter2 = counter2 + 1;
    }
    if (counter3 > 123) {//2sek. failed get sensor data
        slUART_WriteString("0|0|0|0|");
        slUART_LogHexNl(*sensorsAdresses[(sensorNr - 1)]);
        if (sensorNr < sensorsCount) {
            stage = 1;
        } else {
            stage = 0;
        }
        counter3 = 0;
    }
    if (counter == 2100) {//34.4064 sek Next mesurements
        counter = 0;
        counter2 = 0;
        stage = 1;
        slUART_WriteStringNl("----------------");
    }
    if (counter2 == 2840) {//46.348 sek Reset to sending
        slUART_WriteString("server Fail at stage: ");
        slUART_LogDecNl(stage);
        counter = 0;
        counter2 = 0;
        stage = 1;
    }
}

ISR(INT0_vect) {
    status = 0;
    slNRF24_GetRegister(STATUS, &status, 1);
    #if showDebugDataMain == 1
        slUART_WriteString("server STATUS: ");
        slUART_LogBinaryNl(status);
    #endif
    cli();
    if ((status & (1 << 6)) != 0) {//got data
        #if showDebugDataMain == 1
                slUART_WriteStringNl("server got data ");
        #endif
        getDataFromSensor();
        sendingSensorDataViaUart();
        counter = 0;
        counter2 = 0;
        counter3 = 0;
    }
    if ((status & (1 << 5)) != 0) {//send ok
        #if showDebugDataMain == 1
                slUART_WriteStringNl("server sent ok ");
        #endif
        stage = 0;
    }
    sei();
}
