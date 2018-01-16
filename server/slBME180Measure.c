//
// Created by dariusz on 25.02.17.
//
#include <avr/io.h>
#include <string.h>
#include "slBME180Measure.h"
//#include "slUart.h"

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

int16_t calculateTemperature(int32_t temperature) {
    return (int16_t) ((float) temperature/100 * (int16_t) 100);
}

uint16_t calculateHumidity(int32_t humidity) {
    return (uint16_t) ((float) humidity/1024 * (uint16_t) 100);
}

int16_t calculatePressure(uint32_t pressure) {
    return (int16_t) ((float) pressure/256 - (float) 100000);
}

uint16_t calculateVoltage(uint16_t voltage) {
    float v = ((((((float)voltage/16.0)*100.0 * 256.0)/102400.0) * 350.0)/256.0);
    return (uint16_t) ((float) v);
}
uint16_t calculateFotorezistor(uint16_t fotorezistor) {
    float f = ((((((float)fotorezistor/16.0)*100.0 * 256.0)/102400.0) * 350.0)/256.0);
    return (uint16_t) ((float) f);
}