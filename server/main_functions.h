//
// Created by dariusz on 04.01.18.
//

#ifndef CMAKE_AVR_MAIN_FUNCTIONS_H
#define CMAKE_AVR_MAIN_FUNCTIONS_H

#include <avr/io.h>

void PCF8563Start();

void nRF24L01Start();

uint8_t nextSensorNr();

void sensorStart();

void saveDataFromNRF();

void resetNRF24L01p();

void saveErrorData();

uint8_t returnCountErrorsForSensor();

void resetErrors();

uint8_t ifCheckEverySensor();

void sendingSensorDataViaUart();

#endif //CMAKE_AVR_MAIN_FUNCTIONS_H
