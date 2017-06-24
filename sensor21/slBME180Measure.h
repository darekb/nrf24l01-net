//
// Created by dariusz on 25.02.17.
//

#ifndef CMAKE_AVR_SLBME180MEASURE_H
#define CMAKE_AVR_SLBME180MEASURE_H


struct measureStruct {
    int32_t temperature;
    int32_t humidity;
    int64_t pressure;
    uint16_t voltage;
    uint8_t sensorId;
};

union MEASURE {
    struct measureStruct data;
    uint8_t bytes[19];
};

void fillBuferFromMEASURE(const union MEASURE structure, uint8_t *buffer);

union MEASURE returnMEASUREFromBuffer(uint8_t *buffer);

int16_t calculateTemperature(float temperature);

uint16_t calculateHumidity(float humidity);

int16_t calculatePressure(float pressure);

uint16_t calculateVoltage(float voltage);

#endif //CMAKE_AVR_SLBME180MEASURE_H
