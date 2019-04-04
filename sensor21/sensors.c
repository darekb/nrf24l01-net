//
// Created by dariusz on 03.04.19.
//
#include <stdint.h>
#include <time.h> // clock_t, clock, CLOCKS_PER_SEC
#include <stdio.h>
#include <stdlib.h>

#include "sensors.h"
#include "slADC/slAdc.h"
#include "bme/BME280.h"

#define slINA219_SR 16
#define PC1 1
#define PC2 2

MEASURE measure;

typedef struct {
  int32_t mid;
  int64_t sr[slINA219_SR];//tablica z wartoścami do średniej wleczonej
  uint8_t idx;
  int32_t raw;
} Average_DataSTRUCT;

Average_DataSTRUCT pressureAvg, temperatureAvg, humidityAvg, voltageAvg, lightAvg;

void sredniaWleczona(Average_DataSTRUCT *data, uint32_t value) {
  data->raw = value;
  int64_t sr1 = 0;
  uint8_t i = 0;
  data->sr[data->idx++ & (slINA219_SR - 1)] = data->raw; //& (slINA219_SR-1) = maskowanie
  for (i = 0; i < slINA219_SR; i++) {
    sr1 = sr1 + data->sr[i];
  }
  data->mid = (int32_t) sr1 / slINA219_SR;
}

void getDataFromSensors() {
  int32_t temperature;
  int32_t humidity;
  uint32_t pressure;
  uint16_t voltage;
  uint16_t light;
  light = slADC_measure(PC2);
  voltage = slADC_measure(PC1);
  BME280_ReadAll(&temperature, &pressure, &humidity);
  sredniaWleczona(&pressureAvg, pressure);
  //printf("Pressure \traw: %d\tmid: %d\n", pressure, pressureAvg.mid);
  sredniaWleczona(&temperatureAvg, temperature);
  //printf("Temperature \traw: %d\tmid: %d\n", temperature, temperatureAvg.mid);
  sredniaWleczona(&humidityAvg, humidity);
  //printf("Humidity \traw: %d\tmid: %d\n", humidity, humidityAvg.mid);
  sredniaWleczona(&voltageAvg, voltage);
  //printf("Voltage \traw: %d\tmid: %d\n", voltage, voltageAvg.mid);
  sredniaWleczona(&lightAvg, light);
  //printf("Light \traw: %d\tmid: %d\n", light, lightAvg.mid);
}

MEASURE returnMeasure() {
  measure.data.humidity = humidityAvg.mid;
  measure.data.pressure = pressureAvg.mid;
  measure.data.temperature = temperatureAvg.mid;
  measure.data.light = lightAvg.mid;
  measure.data.voltage = voltageAvg.mid;
  measure.data.sensorId = 21;
  return measure;
}
void initSensors() {
  BME280_Init(BME280_OS_T_SKP, BME280_OS_P_SKP, BME280_OS_H_SKP, BME280_FILTER_OFF, BME280_MODE_FORCED,
              BME280_TSB_1000);
  slADC_init();
}


