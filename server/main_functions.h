//
// Created by dariusz on 04.01.18.
//

#ifndef CMAKE_AVR_MAIN_FUNCTIONS_H
#define CMAKE_AVR_MAIN_FUNCTIONS_H


void initAll();

void nRF24L01Start();

uint8_t nextSensorNr();

void sendCommandToSensor();

void saveDataFromNRF();

void resetAfterGotData();

void resetAfterSendData();

void saveErrorData();

uint8_t returnNextStage();

uint8_t ifCheckEverySensor();

void sendingSensorDataViaUart();

#endif //CMAKE_AVR_MAIN_FUNCTIONS_H
