//
// Created by dariusz on 02.01.18.
//
#include <avr/io.h>
#include <util/delay.h>

#define showDebugDataMainFunctions 1

#if showDebugDataMainFunctions == 1

#include "slUart.h"

#endif

#include "slNRF24.h"
#include "slBME180Measure.h"
#include "BME280.h"
#include "slAdc.h"
#include "main_functions.h"


char startStringSensor[] = {'s', 't', 'a', 'r', 't', '-', 's', '2', '1'};
char resetStringSensor[] = {'r', 'e', 's', 'e', 't', '-', 's', '2', '1'};


uint8_t dataFromNRF24L01[9];
union MEASURE BME180measure;
uint8_t buffer[17];
uint16_t nextNumber = 0;

TVOL voltage;
TVOL light;

void initADCData() {
    slADC_initializeData(&light);
    slADC_initializeData(&voltage);
}

void restart() {
    #if showDebugDataMainFunctions == 1
    slUART_WriteString("Total restart.\r\n");
    #endif
    PORTD |= (1 << DDD7);// set as 1
}

uint8_t setBME280Mode() {
    if (BME280_SetMode(BME280_MODE_FORCED)) {
        #if showDebugDataMainFunctions == 1
        slUART_WriteString("BME280 set forced mode error!\r\n");
        #endif
        return 1;
    }
    return 0;
}


void clearData() {
    for (uint8_t i = 0; i < 9; i++) {
        dataFromNRF24L01[i] = 0;
    };
}

uint8_t getDataFromBME280() {
    int32_t temperature, humidity;
    uint32_t pressure;
    if (BME280_ReadAll(&temperature, &pressure, &humidity)) {
        #if showDebugDataMainFunctions == 1
        slUART_WriteString("BME280 read error!\r\n");
        #endif
        return 1;
    }
    BME180measure.data.temperature = temperature;
    BME180measure.data.humidity = humidity;
    BME180measure.data.pressure = pressure;
    BME180measure.data.sensorId = SENSOR_ID;
    return 0;
}

void getDataFromFotorezistor() {
    for (uint8_t i = 0; i < 8; i++) {
        slADC_calculateVol(slADC_measure(PC2), &light);
    }
    BME180measure.data.fotorezistor = (uint16_t) light.adc_mid;
}

void getDataFromADC() {
    for (uint8_t i = 0; i < 8; i++) {
        slADC_calculateVol(slADC_measure(PC1), &voltage);
    }
    BME180measure.data.voltage = (uint16_t) voltage.adc_mid;
    //wynik = (((((wynik/12)*100 * 256)/102400) * 350)/256);
}

void getMesurements() {
    nextNumber = nextNumber + 1;
    for (uint8_t i = 0; i < 17; i++) {
        dataFromNRF24L01[i] = nextNumber;
    };
}


void resetNRF24L01() {
    slNRF24_PowerDown();
    #if showDebugDataMainFunctions == 1
    slUART_WriteStringNl("Sensor21 nRF24L01 Reset");
    #endif
    slNRF24_RxPowerUp();
    slNRF24_FlushTx();
    slNRF24_FlushRx();
    slNRF24_Reset();
    _delay_ms(10);
}

uint8_t isStringMatch(uint8_t *dataFromNRF24L01, char *stringToMatch) {
    uint8_t go = 0;
    uint8_t i = 9;//9 znaków kodu startowego
    while (i--) {
        if (dataFromNRF24L01[i] == stringToMatch[i]) {
            go++;
        }
    }
    if (go == 9) {
        return 1;
    }
    return 0;
}

uint8_t isStartStringMatch() {
    if (isStringMatch(dataFromNRF24L01, resetStringSensor)) {
        restart();
    } else {
        if (isStringMatch(dataFromNRF24L01, startStringSensor)) {
            return 1;
        }
    }
    return 0;
}

void prepeareBuffer() {
    fillBuferFromMEASURE(&BME180measure, buffer);
}


void getDataFromNRF24L01() {
    clearData();
    slNRF24_GetRegister(R_RX_PAYLOAD, dataFromNRF24L01, 9);
    slNRF24_Reset();
    slNRF24_FlushTx();
    slNRF24_FlushRx();
}

uint8_t sendVianRF24L01() {
    slUART_WriteStringNl("Try sent data: ");
    slUART_WriteBuffer(buffer, 17);
    slNRF24_Reset();
    slNRF24_FlushTx();
    slNRF24_FlushRx();
    slNRF24_TxPowerUp();
    slNRF24_TransmitPayload(&buffer, 17);
    slNRF24_RxPowerUp();
    slNRF24_FlushTx();
    slNRF24_FlushRx();
    slNRF24_Reset();
    return 0;
}