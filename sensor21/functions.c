//
// Created by dariusz on 10.06.17.
//

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#include "slUart.h"


#include "slNRF24.h"
#include "slBME180Measure.h"
#include "BME280.h"
#include "slAdc.h"
#include "functions.h"


void clearData() {
    for (uint8_t i = 0; i < 9; i++) {
        data[i] = 0;
    };
}


void setupTimer() {
    TCCR0B |= (1 << CS02) | (1 << CS00);//prescaler 1024
    TIMSK0 |= (1 << TOIE0);//przerwanie przy przepłnieniu timera0
}

void setupInt1() {
    DDRD &= ~(1 << DDD3);     // Clear the PD2 pin
    // PD2 (PCINT0 pin) is now an input
    PORTD |= (1 << PORTD3);    // turn On the Pull-up
    // PD2 is now an input with pull-up enabled
    EICRA |= (1 << ISC11);// INT0 falling edge PD2
    EICRA &= ~(1 << ISC10);// INT0 falling edge PD2
    EIMSK |= (1 << INT1);     // Turns on INT0
    sei();
}

//stage 9
void goSleep() {
    slUART_WriteStringNl("Sensor21 sleep");
    slNRF24_Reset();
    slNRF24_PowerDown();
    sendOk = 1;
    stage = 0;
    counter2 = 0;
}

//stage 10
void goReset() {
    counter = 0;
    slNRF24_PowerDown();
    clearData();
    slUART_WriteStringNl("Sensor21 Reset");
    slNRF24_Reset();
    slNRF24_FlushTx();
    slNRF24_FlushRx();
    slNRF24_RxPowerUp();
    _delay_ms(10);
    //wait for inerupt
    stage = 0;
    sendOk = 0;
    counter2 = 0;
}


//stage 12
void compareStrings() {
    counter = 0;
    counter2 = 0;
    slNRF24_GetRegister(R_RX_PAYLOAD, data, 9);
    slNRF24_Reset();
    slNRF24_FlushTx();
    slNRF24_FlushRx();
    uint8_t go = 0;
    uint8_t i = sizeof(data);
    while (i--) {
        //slUART_WriteByte((char)data[i]);
        if (data[i] == startStringSensor21[i]) {
            go++;
        }
    }
    //slUART_WriteStringNl("-");
    if (go == sizeof(data)) {
        slUART_WriteStringNl("Sensor21 got start command");
        clearData();
        //stage = 13;
        setBME280Mode();
        getDataFromBME280();
        measuerADC();
        sendVianRF24L01();
    } else {
        slUART_WriteStringNl("Sensor21 got false command");
        goReset();
        stage = 0;//wait for interupt from got data
    }
}

//stage13
uint8_t setBME280Mode() {
    counter = 0;
    counter2 = 0;
    //slUART_WriteStringNl("Sensor21 reset BME280");
    if (BME280_SetMode(BME280_MODE_FORCED)) {
        slUART_WriteString("BME280 set forced mode error!\r\n");
        return 1;
    }
    //stage = 14;
    return 0;
}

//stage 14
uint8_t getDataFromBME280() {
    counter = 0;
    counter2 = 0;
    float temperature, humidity, pressure;
    if (BME280_ReadAll(&temperature, &pressure, &humidity)) {

        slUART_WriteString("BME280 read error!\r\n");
        return 1;
    }
    BME180measure.data.temperature = calculateTemperature(temperature);
    BME180measure.data.humidity = calculateHumidity(humidity);
    BME180measure.data.pressure = calculatePressure(pressure);
    BME180measure.data.sensorId = SENSOR_ID;
    //slUART_WriteStringNl("Sensor21 got data from BME280");
    // slUART_LogDecNl(BME180measure.data.temperature);
    // slUART_LogDecNl(BME180measure.data.humidity);
    // slUART_LogDecNl(BME180measure.data.pressure);
    //stage = 15;
    return 0;
}

//stage 15
void measuerADC() {
    counter = 0;
    counter2 = 0;
    //slUART_WriteStringNl("Sensor21 measure ADC");
    float wynik = 0;
    for (uint8_t i = 0; i < 12; i++) {
        wynik = wynik + slADC_measure(PC1);
    }
    wynik = (((110 * ((wynik / 12) * 100)) / 102300) * 350) / 110;
    BME180measure.data.voltage = (uint16_t) wynik;
    //stage = 16;
}

//stage16
uint8_t sendVianRF24L01() {
    counter = 0;
    counter2 = 0;
    clearData();
    fillBuferFromMEASURE(BME180measure, data);
    slNRF24_Reset();
    slNRF24_FlushTx();
    slNRF24_FlushRx();
    slNRF24_TxPowerUp();
    slNRF24_TransmitPayload(&data, 9);
    //slUART_WriteStringNl("Sensor21 Sending data");
    slNRF24_RxPowerUp();
    // slNRF24_FlushTx();
    // slNRF24_FlushRx();
    slNRF24_Reset();
    clearData();
    stage = 0;//goReset
    sendOk = 1;
    return 0;
}