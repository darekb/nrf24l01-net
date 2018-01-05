#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#define showDebugDataMain 1

#if showDebugDataMain == 1

#include "slUart.h"

#endif

#include "main.h"
#include "slNRF24.h"
#include "slSPI.h"
#include "main_functions.h"


void setupTimer();

void setupInt0();


uint8_t status;
volatile uint8_t stage = 0;
//stage
volatile uint16_t counter = 0;
//counter for next mesure
volatile uint16_t counter2 = 0;
//counter for reset mesurements
volatile uint16_t counter3 = 0;

//counter for fail response form sensor
int main(void) {
    // slUART_SimpleTransmitInit();
    // float t,h,p,v;

    // int16_t wynik;
    // t = 2758/100.0;
    // h = 0xb50f/1024.0;
    // p = (float) 0x86e4;
    // wynik = 6119;
    // v = (((110 * ((wynik / 12) * 100)) / 102300) * 350) / 110;
    // BME180measure[0].temperature = calculateTemperature(t);;
    // BME180measure[0].humidity = calculateHumidity(h);
    // BME180measure[0].pressure = calculatePressure(p);
    // BME180measure[0].voltage = (uint16_t) v;
    // BME180measure[0].sensorId = *sensorsId[(sensorNr - 1)];
    // uint8_t i =0;
    // slUART_LogDecWithSign(BME180measure[i].temperature);
    // slUART_WriteString("|");
    // slUART_LogDec(BME180measure[i].humidity);
    // slUART_WriteString("|");
    // slUART_LogDecWithSign(BME180measure[i].pressure);
    // slUART_WriteString("|");
    // slUART_LogDecWithSign(BME180measure[i].voltage);
    // slUART_WriteString("|");
    // slUART_LogDec(BME180measure[i].sensorId);
    // slUART_WriteStringNl("~");
    //*

    #if showDebugDataMain == 1
    slUART_SimpleTransmitInit();
    slUART_Init();
    #endif
    slSPI_Init();
    slNRF24_IoInit();
    nRF24L01Start();
    setupTimer();
    setupInt0();
    sei();
    stage = 1;
    #if showDebugDataMain == 1
    slUART_WriteStringNl("\nStart server");
    #endif
    _delay_ms(500);
    slNRF24_Reset();
    while (1) {
        switch (stage) {
            case 1:
                sensorStart();
                stage = 0;//wait for intrrupt
                break;
        }
    }
    return 0;
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
        saveErrorData();
        stage = returnNextStage();
        sendingSensorDataViaUart();
        counter3 = 0;
    }
    if (counter == 2100) {//34.4064 sek Next mesurements
        counter = 0;
        counter2 = 0;
        stage = 1;
        #if showDebugDataMain == 1
        slUART_WriteStringNl("----------------");
        #endif
    }
    if (counter2 == 2840) {//46.348 sek Reset to sending
        #if showDebugDataMain == 1
        slUART_WriteString("server Fail at stage: ");
        slUART_LogDecNl(stage);
        #endif
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
        saveDataFromNRF();
        stage = returnNextStage();
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
