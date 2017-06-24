//
// Created by dariusz on 25.02.17.
//
#include <avr/io.h>
#include <string.h>
#include "slBME180Measure.h"
//#include "slUart.h"

void fillBuferFromMEASURE(const union MEASURE structure, uint8_t *buffer) {
    for (uint8_t i = 0; i < 19; i++) {
        buffer[i] = structure.bytes[i];
    }
}

union MEASURE returnMEASUREFromBuffer(uint8_t *buffer) {
    union MEASURE tmp;
    for (uint8_t i = 0; i < 19; i++) {
        tmp.bytes[i] = buffer[i];
    }
    return tmp;
}