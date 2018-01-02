#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <avr/wdt.h>


#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#define showDebugDataMain 1

#include "main.h"


#include "slUart.h"


#include "slNRF24.h"
#include "slBME180Measure.h"
#include "slI2C.h"
#include "BME280.h"
#include "slSPI.h"
#include "slAdc.h"

#define SENSOR_ID 12

void stage12();

void clearData();

void setupTimer();

void setupInt1();

void goSleep();

void restart();

void goReset();

void getDataFromNRF24L01();

void compareStrings();

uint8_t setBME280Mode();

uint8_t getDataFromBME280();

void getDataFromADC();

uint8_t sendVianRF24L01();

uint8_t dataFromNRF24L01[9];
uint8_t status;
union MEASURE BME180measure;
volatile uint8_t stage;
volatile uint8_t errors = 0;
volatile uint16_t counter = 0;
volatile uint16_t isTimeoutError = 0;
const char startStringSensor12[] = {'s', 't', 'a', 'r', 't', '-', 's', '1', '2'};

int main(void) {
    slUART_SimpleTransmitInit();
    slUART_WriteString("start.\r\n");
    slI2C_Init();
    if (BME280_Init(BME280_OS_T_1, BME280_OS_P_1, BME280_OS_H_1, BME280_FILTER_OFF, BME280_MODE_FORCED,
                    BME280_TSB_1000)) {
        slUART_WriteString("BMP280 init error.\r\n");
    } else {
        slUART_WriteString("BMP280 init done.\r\n");
    }
    slSPI_Init();
    slNRF24_IoInit();
    setupTimer();
    setupInt1();
    slNRF24_Init();
    slADC_init();
    sei();
    stage = 10;
    goReset();

    while (1) {
        switch (stage) {
            case 10:
                goReset();
                break;
            case 12://get measures
                stage12();
                break;
        }
    }
    return 0;
}

void stage12(){
    counter = 0;
    setBME280Mode();
    getDataFromBME280();
    getDataFromADC();
    slUART_WriteStringNl("Sensor12 got data from BME280");
    slUART_LogDecWithSign(BME180measure.data.temperature);
    slUART_WriteString("|");
    slUART_LogHex32(BME180measure.data.humidity);
    slUART_WriteString("|");
    slUART_LogHex32(BME180measure.data.pressure);
    slUART_WriteString("|");
    slUART_LogDec(BME180measure.data.voltage);
    slUART_WriteString("|");
    slUART_LogDec(BME180measure.data.sensorId);
    slUART_WriteStringNl("~");
    stage = 0;
}


void clearData() {
    for (uint8_t i = 0; i < 9; i++) {
        dataFromNRF24L01[i] = 0;
    };
}


void setupTimer() {
    TCCR0 |= (1 << CS02) | (1 << CS00);//prescaler 1024
    TIMSK |= (1 << TOIE0);//przerwanie przy przepłnieniu timera0
}

void setupInt1() {
    DDRD &= ~(1 << DDD3);     // Clear the PD2 pin
    // PD2 (PCINT0 pin) is now an input
    PORTD |= (1 << PORTD3);    // turn On the Pull-up
    // PD2 is now an input with pull-up enabled
    MCUCR |= (1 << ISC11);// INT0 falling edge PD2
    MCUCR &= ~(1 << ISC10);// INT0 falling edge PD2
    GICR |= (1 << INT1);     // Turns on INT0
}

//stage 9
void goSleep() {
    slUART_WriteStringNl("Sensor12 sleep");
    slNRF24_Reset();
    slNRF24_PowerDown();
    stage = 0;
}

void restart(){
    slUART_WriteString("Total restart.\r\n");
    wdt_enable(WDTO_15MS);
    //wdt_disable();
}

void goReset() {
    counter = 0;
    slNRF24_PowerDown();
    clearData();
    slUART_WriteStringNl("Sensor12 Reset");
    slNRF24_Reset();
    slNRF24_FlushTx();
    slNRF24_FlushRx();
    slNRF24_RxPowerUp();
    _delay_ms(10);
    //wait for inerupt
    stage = 0;
    isTimeoutError = 0;
}

void getDataFromNRF24L01(){
    slNRF24_GetRegister(R_RX_PAYLOAD, dataFromNRF24L01, 9);
    slNRF24_Reset();
    slNRF24_FlushTx();
    slNRF24_FlushRx();
}

void compareStrings() {
    counter = 0;
    uint8_t go = 0;
    uint8_t i = sizeof(dataFromNRF24L01);
    while (i--) {
        //slUART_WriteByte((char)dataFromNRF24L01[i]);
        if (dataFromNRF24L01[i] == startStringSensor12[i]) {
            go++;
        }
    }
    //slUART_WriteStringNl("-");
    if (go == sizeof(dataFromNRF24L01)) {
        slUART_WriteStringNl("Sensor12 got start command");
        clearData();
        //stage = 13;
        sendVianRF24L01();
        errors = 0;
    } else {
        slUART_WriteStringNl("Sensor12 got false command");
        goReset();
        stage = 0;//wait for interupt from got dataFromNRF24L01
    }
}

//stage13
uint8_t setBME280Mode() {
    //slUART_WriteStringNl("Sensor12 reset BME280");
    if (BME280_SetMode(BME280_MODE_FORCED)) {
        slUART_WriteString("BME280 set forced mode error!\r\n");
        return 1;
    }
    return 0;
}

//stage 14
uint8_t getDataFromBME280() {
    int32_t temperature, humidity;
    int64_t pressure;
    if (BME280_ReadAll(&temperature, &pressure, &humidity)) {

        slUART_WriteString("BME280 read error!\r\n");
        return 1;
    }
    BME180measure.data.temperature = temperature;
    BME180measure.data.humidity = humidity;
    BME180measure.data.pressure = pressure;
    BME180measure.data.sensorId = SENSOR_ID;
    return 0;
}

//stage 15
void getDataFromADC() {
    counter = 0;
    //slUART_WriteStringNl("Sensor12 measure ADC");
    int16_t wynik = 0;
    for (uint8_t i = 0; i < 12; i++) {
        wynik = wynik + slADC_measure(PC1);
    }
    //wynik = (((110 * ((wynik / 12) * 100)) / 102300) * 350) / 110;
    BME180measure.data.voltage = (uint16_t) wynik;
}

//stage16
uint8_t sendVianRF24L01() {
    cli();
    counter = 0;
    isTimeoutError = 0;
    uint8_t buffer[19];
    fillBuferFromMEASURE(&BME180measure, buffer);
    slNRF24_Reset();
    slNRF24_FlushTx();
    slNRF24_FlushRx();
    slNRF24_TxPowerUp();
    slNRF24_TransmitPayload(&buffer, 19);
    //slUART_WriteStringNl("Sensor12 Sending data");
    slNRF24_RxPowerUp();
    slNRF24_Reset();
    clearData();
    stage = 0;
    sei();
    return 0;
}


ISR(TIMER0_OVF_vect) {
    //co 0.032768sek.
    counter = counter + 1;
    if (counter == 200) {//6.55 sek Next mesurements
        counter = 0;
        stage = 12;//make measure
    }
    isTimeoutError = isTimeoutError + 1;
    if (isTimeoutError >= 1250) {//40.96 sek after reset
        counter = 0;
        errors = errors + 1;
        isTimeoutError = 0;
        slUART_WriteStringNl("Sensor12 FAIL");
        if(errors > 3){
            restart();
            errors =0;
            wdt_disable();
        }
    }
}

ISR(INT1_vect) {
    status = 0;
    counter = 0;
    slNRF24_GetRegister(STATUS, &status, 1);
    cli();
    if ((status & (1 << 6)) != 0) {//got data
        getDataFromNRF24L01();
        compareStrings();
    }
    if ((status & (1 << 5)) != 0) {//send ok
        stage = 0;
        errors = 0;
    }
    sei();
}
