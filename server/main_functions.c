//
// Created by dariusz on 04.01.18.
//

#include <avr/io.h>

#define showDebugDataMainFunctions 1
#define sensorsCount 3

#include "slUart.h"
#include "slNRF24.h"
#include "slBME180Measure.h"
#include "main_functions.h"


uint8_t dataFromNRF24L01[17];
union MEASURE BME180measure[sensorsCount];


volatile uint8_t sensorNr = 0;
//nr of sensor from sensorsStrings

char sensorsStrings[sensorsCount][17] = {
        {'s', 't', 'a', 'r', 't', '-', 's', '2', '1'},
        {'s', 't', 'a', 'r', 't', '-', 's', '1', '1'},
        {'s', 't', 'a', 'r', 't', '-', 's', '1', '2'}
};
char resetSensorsStrings[sensorsCount][17] = {
        {'r', 'e', 's', 'e', 't', '-', 's', '2', '1'},
        {'r', 'e', 's', 'e', 't', '-', 's', '1', '1'},
        {'r', 'e', 's', 'e', 't', '-', 's', '1', '2'}
};

uint8_t sensorsId[sensorsCount][1] = {
        {21},
        {11},
        {12}
};


uint8_t sensorsAdresses[sensorsCount][1] = {
        {0x21},
        {0x11},
        {0x12}
};

void clearData() {
    for (uint8_t i = 0; i < 17; i++) {
        dataFromNRF24L01[i] = 0;
    };
}


uint8_t nextSensorNr() {
    sensorNr = sensorNr + 1;
    if (sensorNr > sensorsCount) {
        sensorNr = 1;
    }
    return sensorNr;
}

uint8_t returnNextStage() {
    if (sensorNr < sensorsCount) {
        return 1;
    }
    return 0;
}

void nRF24L01Start() {
    slNRF24_Init(*sensorsAdresses[0]);
    slUART_SimpleTransmitInit();
    slUART_Init();
}


void sensorStart() {
    nextSensorNr();
    slNRF24_Reset();
    slNRF24_FlushTx();
    slNRF24_FlushRx();
    #if showDebugDataMainFunctions == 1
    slUART_WriteString("S");
    slUART_LogHexNl(*sensorsAdresses[(sensorNr - 1)]);
    #endif
    slNRF24_TxPowerUp(*sensorsAdresses[(sensorNr - 1)], sensorNr);
    slNRF24_TransmitPayload(&sensorsStrings[(sensorNr - 1)], 9);
    clearData();
}

void resetAfterGotData(){
    slNRF24_Reset();
    slNRF24_RxPowerUp(*sensorsAdresses[(sensorNr - 1)], sensorNr);
}

void saveDataFromNRF() {
    slNRF24_GetRegister(R_RX_PAYLOAD, dataFromNRF24L01, 17);
    slUART_WriteStringNl("Get buffer from sensor ");
    slUART_LogHexNl(*sensorsAdresses[(sensorNr - 1)]);
    slUART_WriteBuffer(dataFromNRF24L01, 17);
    BME180measure[(sensorNr - 1)] = returnMEASUREFromBuffer(dataFromNRF24L01);
    #if showDebugDataMainFunctions == 1
    slUART_WriteString("OK");
    slUART_LogHexNl(*sensorsAdresses[(sensorNr - 1)]);
    slUART_WriteStringNl("Server got data from Sensor21");
    slUART_LogHex32WithSign(BME180measure[(sensorNr - 1)].data.temperature);
    slUART_WriteString("|");
    slUART_LogHex32WithSign(BME180measure[(sensorNr - 1)].data.humidity);
    slUART_WriteString("|");
    slUART_LogHex32(BME180measure[(sensorNr - 1)].data.pressure);
    slUART_WriteString("|");
    slUART_LogHex(BME180measure[(sensorNr - 1)].data.voltage);
    slUART_WriteString("|");
    slUART_LogHex(BME180measure[(sensorNr - 1)].data.fotorezistor);
    slUART_WriteString("|");
    slUART_LogDec(BME180measure[(sensorNr - 1)].data.sensorId);
    slUART_WriteStringNl("~");
    #endif
    clearData();
}

void resetBMEData(uint8_t sensorId) {
    BME180measure[sensorId].data.temperature = 0;
    BME180measure[sensorId].data.humidity = 0;
    BME180measure[sensorId].data.pressure = 0;
    BME180measure[sensorId].data.voltage = 0;
    BME180measure[sensorId].data.fotorezistor = 0;
    BME180measure[sensorId].data.sensorId = *sensorsId[sensorId];
}

void saveErrorData() {
    resetBMEData((sensorNr - 1));
    #if showDebugDataMainFunctions == 1
    slUART_WriteString("F");
    slUART_LogHexNl(*sensorsAdresses[(sensorNr - 1)]);
    #endif
}

uint8_t ifCheckEverySensor() {
    if (sensorNr >= sensorsCount) {
        return 1;
    }
    return 0;
}

void sendingSensorDataViaUart() {
    #if showDebugDataMainFunctions == 1
    slUART_WriteStringNl("server sendingSensorDataViaUart");
    #endif
    for (uint8_t i = 0; i < sensorsCount; i++) {
        slUART_LogDecWithSign(calculateTemperature(BME180measure[i].data.temperature));
        slUART_WriteString("|");
        slUART_LogDec(calculateHumidity(BME180measure[i].data.humidity));
        slUART_WriteString("|");
        slUART_LogDecWithSign(calculatePressure(BME180measure[i].data.pressure));
        slUART_WriteString("|");
        slUART_LogDec(calculateVoltage(BME180measure[i].data.voltage));
        slUART_WriteString("|");
        slUART_LogDec(calculateFotorezistor(BME180measure[i].data.fotorezistor));
        slUART_WriteString("|");
        slUART_LogDec(BME180measure[i].data.sensorId);
        slUART_WriteString("~");
    }
    slUART_WriteStringNl("");

    for (uint8_t i = 0; i < sensorsCount; i++) {
        resetBMEData(i);
    }
}
