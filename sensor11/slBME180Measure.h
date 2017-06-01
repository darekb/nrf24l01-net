//
// Created by dariusz on 25.02.17.
//

#ifndef CMAKE_AVR_SLBME180MEASURE_H
#define CMAKE_AVR_SLBME180MEASURE_H


struct MEASURE {
    int32_t temperature;
    int32_t humidity;
    int64_t pressure;
    //(pressure - 1000)*100
    uint16_t voltage;
    uint8_t sensorId;
};

void fillBuferFromMEASURE(const struct MEASURE structure, uint8_t *buffer);

struct MEASURE returnMEASUREFromBuffer(uint8_t *buffer);

int32_t calculateTemperature(int32_t temperature);

uint32_t calculateHumidity(int32_t humidity);

int64_t calculatePressure(int64_t pressure);

uint16_t calculateVoltage(int16_t voltage);
//void testBME180Measure(void);

#endif //CMAKE_AVR_SLBME180MEASURE_H
