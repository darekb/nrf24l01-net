//
// Created by dariusz on 25.02.17.
//

#ifndef CMAKE_AVR_SLBME180MEASURE_H
#define CMAKE_AVR_SLBME180MEASURE_H


struct measureStruct {
    int32_t temperature;
    int32_t humidity;
    uint32_t pressure;
    uint16_t voltage;
    uint8_t sensorId;
};

union MEASURE {
    struct measureStruct data;
    uint8_t bytesData[15];
};

void fillBuferFromMEASURE(union MEASURE *structure, uint8_t *buffer);

union MEASURE returnMEASUREFromBuffer(uint8_t *buffer);

#endif //CMAKE_AVR_SLBME180MEASURE_H
