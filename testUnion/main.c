#include <avr/io.h>
//https://www.youtube.com/watch?v=38h4-5FDdV4
//https://www.allaboutcircuits.com/news/teardown-tuesday-ikea-wireless-lamp/
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include "main.h"
#include "slUart.h"

int main(void) {
    slUART_Init();
    slUART_WriteString("start.\r\n");
    union MEASURE BME180measure;
    union MEASURE t2;
    BME180measure.data.temperature = 856;
    BME180measure.data.humidity = 6818;
    BME180measure.data.pressure = 1235;
    BME180measure.data.voltage = 33;
    BME180measure.data.sensorId = 11;
    t2.data.temperature = 0;
    t2.data.humidity = 0;
    t2.data.pressure = 0;
    t2.data.voltage = 0;
    t2.data.sensorId = 21;
    slUART_WriteString("\r\n***************************\r\n");
    slUART_WriteBuffer(BME180measure.bytes, 19);
    slUART_WriteString("\r\n***************************\r\n");
    BME180measure.data.temperature = 121;
    BME180measure.data.humidity = 122;
    BME180measure.data.pressure = 123;
    BME180measure.data.voltage = 12*33;
    slUART_WriteString("\r\n***************************\r\n");
    slUART_WriteBuffer(t2.bytes, 19);
    slUART_WriteString("\r\n***************************\r\n");
    for(uint8_t i = 0; i < 19; i++){
        t2.bytes[i] = BME180measure.bytes[i];
    }
    slUART_LogDecNl(t2.data.temperature);
    slUART_LogDecNl(BME180measure.data.temperature);
    slUART_LogDecNl(t2.data.humidity);
    slUART_LogDecNl(BME180measure.data.humidity);
    slUART_LogDecNl(t2.data.pressure);
    slUART_LogDecNl(BME180measure.data.pressure);
    slUART_LogDecNl(t2.data.voltage);
    slUART_LogDecNl(BME180measure.data.voltage);
    slUART_LogDecNl(t2.data.sensorId);
    slUART_LogDecNl(BME180measure.data.sensorId);
    // while (1) {
    // }
}