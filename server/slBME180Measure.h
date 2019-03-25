//
// Created by dariusz on 25.02.17.
//

#ifndef CMAKE_AVR_SLBME180MEASURE_H
#define CMAKE_AVR_SLBME180MEASURE_H

#define DATA_UPLOAD_SIZE 17

#include <avr/io.h>

struct measureStruct {
  int32_t temperature;
  int32_t humidity;
  uint32_t pressure;
  uint16_t voltage;
  uint16_t fotorezistor;
  uint8_t sensorId;
};

union MEASURE {
  struct measureStruct data;
  uint8_t bytesData[DATA_UPLOAD_SIZE];
};

void fillBuferFromMEASURE(union MEASURE *structure, uint8_t *buffer);

union MEASURE returnMEASUREFromBuffer(uint8_t *buffer);

int16_t calculateTemperature(int32_t temperature);

uint16_t calculateHumidity(int32_t humidity);

int16_t calculatePressure(uint32_t pressure);

uint16_t calculateVoltage(uint16_t voltage);

uint16_t calculateFotorezistor(uint16_t fotorezistor);

#endif //CMAKE_AVR_SLBME180MEASURE_H
