//
// Created by dariusz on 25.02.17.
//
#include <avr/io.h>
#include <string.h>
#include "slBME180Measure.h"
//#include "slUart.h"

void fillBuferFromMEASURE(union MEASURE *structure, uint8_t *buffer) {
    for (uint8_t i = 0; i < 17; i++) {
        buffer[i] = structure->bytesData[i];
    }
}

union MEASURE returnMEASUREFromBuffer(uint8_t *buffer) {
    union MEASURE tmp;
    for (uint8_t i = 0; i < 17; i++) {
        tmp.bytesData[i] = buffer[i];
    }
    return tmp;
}

int16_t calculateTemperature(float temperature) {
    return (int16_t) ((float) temperature/100 * (int16_t) 100);
}

uint16_t calculateHumidity(float humidity) {
    return (uint16_t) ((float) humidity/1024 * (uint16_t) 100);
}

int16_t calculatePressure(float pressure) {
    return (int16_t) ((float) pressure/256 - (float) 100000);
}

uint16_t calculateVoltage(float voltage) {
    float v = (((((voltage/16)*100 * 256)/102400) * 350)/256);
    return (uint16_t) ((float) v * (uint16_t) 100);
}
uint16_t calculateFotorezistor(float fotorezistor) {
    float f = (((((fotorezistor/16)*100 * 256)/102400) * 350)/256);
    return (uint16_t) ((float) f * (uint16_t) 100);
}