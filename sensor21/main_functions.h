//
// Created by dariusz on 02.01.18.
//

#ifndef CMAKE_AVR_MAIN_FUNCTIONS_H
#define CMAKE_AVR_MAIN_FUNCTIONS_H


#define SENSOR_ID 12


void restart();

void goReset();

void getDataFromNRF24L01(uint8_t *dataFromNRF24L01);

uint8_t isStartStringMatch(uint8_t *dataFromNRF24L01);

uint8_t setBME280Mode();

uint8_t getDataFromBME280(union MEASURE *BME180measure);

void getDataFromADC(union MEASURE *BME180measure);

void getMesurements(union MEASURE *BME180measure);

uint8_t sendVianRF24L01(uint8_t *buffer);


#endif //CMAKE_AVR_MAIN_FUNCTIONS_H
