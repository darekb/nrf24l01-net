//
// Created by dariusz on 04.01.18.
//

#ifndef CMAKE_AVR_MAIN_FUNCTIONS_H
#define CMAKE_AVR_MAIN_FUNCTIONS_H

void nRF24L01Start();

void sensorStart();

void saveDataFromNRF();
void resetAfterGotData();
void resetAfterSendData();

void saveErrorData();

uint8_t returnNextStage();

uint8_t ifCheckEverySensor();

void sendingSensorDataViaUart();

#endif //CMAKE_AVR_MAIN_FUNCTIONS_H
