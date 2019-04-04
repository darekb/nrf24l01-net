//
// Created by dariusz on 03.04.19.
//

#ifndef NRFTEST_SENSORS_H
#define NRFTEST_SENSORS_H

#define DATA_UPLOAD_SIZE 17

typedef struct {
  int32_t temperature;
  int32_t humidity;
  uint32_t pressure;
  uint16_t voltage;
  uint16_t light;
  uint8_t sensorId;
} measureStruct;

typedef union {
  measureStruct data;
  uint8_t bytesData[DATA_UPLOAD_SIZE];
} MEASURE;

void initSensors();
void getDataFromSensors();
MEASURE returnMeasure();

#endif //NRFTEST_SENSORS_H
