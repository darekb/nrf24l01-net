//
// Created by dariusz on 02.01.18.
//

#ifndef CMAKE_AVR_MAIN_FUNCTIONS_H
#define CMAKE_AVR_MAIN_FUNCTIONS_H



#define DATA_UPLOAD_SIZE 17

void initADCData();

void restart();

void resetNRF24L01();

void getDataFromNRF24L01();

uint8_t isStartStringMatch();

void getMesurements();

void prepeareBuffer();

uint8_t sendVianRF24L01();

void resetAfterSendData();

#endif //CMAKE_AVR_MAIN_FUNCTIONS_H
