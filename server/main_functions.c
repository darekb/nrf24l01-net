//
// Created by dariusz on 04.01.18.
//

#include <avr/io.h>
#include <util/delay.h>

#define showDebugDataMainFunctions 0
#define sensorsCount 5
#include "global_definitions.h"
#include "slUart.h"
#include "slNRF24.h"
#include "slBME180Measure.h"
#include "slPCF8563.h"
#include "main_functions.h"

uint8_t dataFromNRF24L01[PAYLOAD_SIZE];
union MEASURE BME180measure[sensorsCount];

volatile uint8_t sensorNr = 0;
//nr of sensor from sensorsStrings

char sensorsStrings[sensorsCount][PAYLOAD_SIZE] = {
    {'s', 't', 'a', 'r', 't', '-', 's', '2', '1'},//sypialnia out
    {'s', 't', 'a', 'r', 't', '-', 's', '7', '1'},//sypialnia in

    {'s', 't', 'a', 'r', 't', '-', 's', '2', '2'},//salon out
    {'s', 't', 'a', 'r', 't', '-', 's', '7', '2'},//salon in

    {'s', 't', 'a', 'r', 't', '-', 's', '7', '3'},//dziecięcy
};
char resetSensorsStrings[sensorsCount][PAYLOAD_SIZE] = {
    {'r', 'e', 's', 'e', 't', '-', 's', '2', '1'},//sypialnia out
    {'r', 'e', 's', 'e', 't', '-', 's', '7', '1'},//sypialnia in

    {'r', 'e', 's', 'e', 't', '-', 's', '2', '2'},//salon out
    {'r', 'e', 's', 'e', 't', '-', 's', '7', '2'},//salon in

    {'r', 'e', 's', 'e', 't', '-', 's', '7', '3'},//dziecięcy
};

uint8_t sensorsId[sensorsCount] = {
    21,//sypialnia out
    71,//sypialnia in
    22,//salon out
    72,//salon in
    73//dziecięcy
};

uint8_t sensorsErrors[sensorsCount] = {0, 0, 0, 0};

uint8_t sensorsAdresses[sensorsCount] = {
    0x21,//sypialnia out
    0x71,//sypialnia in
    0x22,//salon out
    0x72,//salon in
    0x73//dziecięcy
};

slPCF8563_DateTime dateTime;

void clearData() {
  for (uint8_t i = 0; i < PAYLOAD_SIZE; i++) {
    dataFromNRF24L01[i] = 0;
  };
}

uint8_t nextSensorNr() {
  sensorNr = sensorNr + (uint8_t) 1;
  if (sensorNr > sensorsCount) {
    sensorNr = 1;
  }
  return sensorNr;
}

void setDateTime() {
  dateTime.year = 2019;
  dateTime.month = 3;
  dateTime.day = 19;
  dateTime.weekday = 2;
  dateTime.hour = 0;
  dateTime.min = 37;
  dateTime.sec = 27;
  slPCF8563_SetData(&dateTime);
}

void PCF8563Start() {
  slPCF8563_Init(0);
  setDateTime();
}

void nRF24L01Start() {
  slNRF24_Setup();
}

void sensorStart() {
  slNRF24_Reset();
  slNRF24_FlushTx();
  slNRF24_FlushRx();
  slUART_WriteString("S");
  slUART_LogHexNl(sensorsAdresses[(sensorNr - 1)]);
//  slUART_WriteString("SensorNr:");
//  slUART_LogDecNl(sensorNr);
  slNRF24_TxPowerUp(sensorsAdresses[(sensorNr - 1)]);
  slNRF24_TransmitPayload(&sensorsStrings[(sensorNr - 1)], PAYLOAD_SIZE);
  _delay_ms(50);
  //resetNRF24L01p();
  clearData();
}

void returnTime() {
  slPCF8563_ResetDateTime(&dateTime);
  slPCF8563_GetData(&dateTime);
  slUART_LogDec(dateTime.year);
  slUART_WriteString("-");
  slUART_LogDec(dateTime.month);
  slUART_WriteString("-");
  slUART_LogDec(dateTime.day);
  slUART_WriteString(" ");
//    slUART_LogDec(dateTime.weekday);
//    slUART_WriteString("  ");
  slUART_LogDec(dateTime.hour);
  slUART_WriteString(":");
  slUART_LogDec(dateTime.min);
  slUART_WriteString(":");
  slUART_LogDec(dateTime.sec);
}

void resetNRF24L01p() {
  slNRF24_FlushRx();
  slNRF24_FlushTx();
  slNRF24_SetPayloadSize(PAYLOAD_SIZE);
  slNRF24_RxPowerUp(sensorsAdresses[(sensorNr - 1)]);
  slNRF24_Reset();
}
void saveDataFromNRF() {
  slNRF24_GetRegister(R_RX_PAYLOAD, dataFromNRF24L01, PAYLOAD_SIZE);
  slUART_WriteString("OK");
  slUART_LogHexNl(sensorsAdresses[(sensorNr - 1)]);
  #if showDebugDataMainFunctions == 1
  slUART_WriteString("Get buffer from Sensor");
  slUART_LogHexNl(sensorsAdresses[(sensorNr - 1)]);
  slUART_WriteBuffer(dataFromNRF24L01, PAYLOAD_SIZE);
  #endif
  BME180measure[(sensorNr - 1)] = returnMEASUREFromBuffer(dataFromNRF24L01);
  //sensorsErrors[(sensorNr - 1)] = 0;
  #if showDebugDataMainFunctions == 1
  slUART_LogHexNl(sensorsAdresses[(sensorNr - 1)]);
  slUART_WriteString("Server got data from Sensor");
  slUART_LogHexNl(sensorsAdresses[(sensorNr - 1)]);
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
  BME180measure[sensorId].data.sensorId = sensorsId[sensorId];
}

void saveErrorData() {
  resetBMEData((sensorNr - (uint8_t) 1));
  sensorsErrors[(sensorNr - (uint8_t) 1)] = sensorsErrors[(sensorNr - (uint8_t) 1)] + (uint8_t) 1;
  slUART_WriteString("F");
  slUART_LogHexNl(sensorsAdresses[(sensorNr - 1)]);
}

uint8_t returnCountErrorsForSensor() {
  return sensorsErrors[(sensorNr - 1)];
}

void resetErrors() {
  for (uint8_t i = 0; i < sensorsCount; i++) {
    sensorsErrors[i] = 0;
  }
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
  returnTime();
  slUART_WriteStringNl("");

  for (uint8_t i = 0; i < sensorsCount; i++) {
    resetBMEData(i);
  }
}
