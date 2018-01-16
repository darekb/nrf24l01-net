//
// Created by dariusz on 25.02.17.
//
#include <avr/io.h>
#include "slBME180Measure.h"

void fillBuferFromMEASURE(union MEASURE *structure, uint8_t *buffer) {
    for (uint8_t i = 0; i < DATA_UPLOAD_SIZE; i++) {
        buffer[i] = structure->bytesData[i];
    }
}

union MEASURE returnMEASUREFromBuffer(uint8_t *buffer) {
    union MEASURE tmp;
    for (uint8_t i = 0; i < DATA_UPLOAD_SIZE; i++) {
        tmp.bytesData[i] = buffer[i];
    }
    return tmp;
}