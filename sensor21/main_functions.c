//
// Created by dariusz on 02.01.18.
//
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>


#include "slUart.h"


#include "slNRF24.h"
#include "slBME180Measure.h"
#include "slI2C.h"
#include "BME280.h"
#include "slSPI.h"
#include "slAdc.h"
#include "main_functions.h"


const char startStringSensor12[] = {'s', 't', 'a', 'r', 't', '-', 's', '1', '2'};

void restart() {
    slUART_WriteString("Total restart.\r\n");
    PORTD |= (1 << DDD7);// set as 1
}

uint8_t setBME280Mode() {
    if (BME280_SetMode(BME280_MODE_FORCED)) {
        slUART_WriteString("BME280 set forced mode error!\r\n");
        return 1;
    }
    return 0;
}


void clearData(uint8_t *dataFromNRF24L01) {
    for (uint8_t i = 0; i < 9; i++) {
        dataFromNRF24L01[i] = 0;
    };
}

uint8_t getDataFromBME280(union MEASURE *BME180measure) {
    int32_t temperature, humidity;
    uint32_t pressure;
    if (BME280_ReadAll(&temperature, &pressure, &humidity)) {
        slUART_WriteString("BME280 read error!\r\n");
        return 1;
    }
    BME180measure->data.temperature = temperature;
    BME180measure->data.humidity = humidity;
    BME180measure->data.pressure = pressure;
    BME180measure->data.sensorId = SENSOR_ID;
    return 0;
}

void getDataFromADC(union MEASURE *BME180measure) {
    int16_t wynik = 0;
    for (uint8_t i = 0; i < 12; i++) {
        wynik = wynik + slADC_measure(PC1);
    }
    //wynik = (((110 * ((wynik / 12) * 100)) / 102300) * 350) / 110;
    BME180measure->data.voltage = (uint16_t) wynik;
}

void getMesurements(union MEASURE *BME180measure) {
    setBME280Mode();
    getDataFromBME280(BME180measure);
    getDataFromADC(BME180measure);
    slUART_WriteStringNl("Sensor12 got data from BME280");
    slUART_LogHex32WithSign(BME180measure->data.temperature);
    slUART_WriteString("|");
    slUART_LogHex32WithSign(BME180measure->data.humidity);
    slUART_WriteString("|");
    slUART_LogHex32(BME180measure->data.pressure);
    slUART_WriteString("|");
    slUART_LogHex(BME180measure->data.voltage);
    slUART_WriteString("|");
    slUART_LogDec(BME180measure->data.sensorId);
    slUART_WriteStringNl("~");
}


void goReset() {
    slNRF24_PowerDown();
    slUART_WriteStringNl("Sensor12 nRF24L01 Reset");
    slNRF24_Reset();
    slNRF24_FlushTx();
    slNRF24_FlushRx();
    slNRF24_RxPowerUp();
    _delay_ms(10);
    //wait for inerupt
}


uint8_t isStartStringMatch(uint8_t *dataFromNRF24L01) {
    uint8_t go = 0;
    uint8_t i = 9;//sizeof(dataFromNRF24L01);
    while (i--) {
//        slUART_WriteByte((char) dataFromNRF24L01[i]);
//        slUART_WriteString("-");
//        slUART_WriteByte(startStringSensor12[i]);
//        slUART_WriteStringNl("?");
        if (dataFromNRF24L01[i] == startStringSensor12[i]) {
            go++;
        }
    }
    if (go == 9) {
        return 1;
    } else {
        return 0;
    }
    clearData(dataFromNRF24L01);
}


void getDataFromNRF24L01(uint8_t *dataFromNRF24L01) {
    slNRF24_GetRegister(R_RX_PAYLOAD, dataFromNRF24L01, 9);
    slNRF24_Reset();
    slNRF24_FlushTx();
    slNRF24_FlushRx();
}

uint8_t sendVianRF24L01(uint8_t *buffer) {
    slNRF24_Reset();
    slNRF24_FlushTx();
    slNRF24_FlushRx();
    slNRF24_TxPowerUp();
    slNRF24_TransmitPayload(&buffer, 15);
    slNRF24_RxPowerUp();
    slNRF24_Reset();
    return 0;
}