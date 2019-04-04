//
// Created by dariusz on 03.04.19.
//

#ifndef NRFTEST_RADIO_H
#define NRFTEST_RADIO_H
#include <stdint.h>
void initRadio();
char *getCommandFromRadio();
uint8_t *getDataFromRadio();
void sentDataViaRadio(void *data, uint8_t dataSize);
void afterSendDataViaRadio();
#endif //NRFTEST_RADIO_H
