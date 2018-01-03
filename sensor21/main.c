#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>


#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#define showDebugDataMain 1

#include "main.h"


#include "slUart.h"


#include "slNRF24.h"
#include "slBME180Measure.h"
#include "slI2C.h"
#include "BME280.h"
#include "slSPI.h"
#include "slAdc.h"
#include "main_functions.h"

void setupResetPin();

void setupTimer();

void setupInt1();

uint8_t status;
volatile uint8_t stage;
volatile uint8_t errors = 0;
volatile uint16_t counter = 0;
volatile uint16_t isTimeoutError = 0;

uint8_t dataFromNRF24L01[9];
union MEASURE BME180measure;
uint8_t buffer[15];

int main(void) {
    setupResetPin();
    slUART_SimpleTransmitInit();
    slUART_WriteString("start.\r\n");
    slI2C_Init();
    if (BME280_Init(BME280_OS_T_1, BME280_OS_P_1, BME280_OS_H_1, BME280_FILTER_OFF, BME280_MODE_FORCED,
                    BME280_TSB_1000)) {
        slUART_WriteString("BMP280 init error.\r\n");
    } else {
        slUART_WriteString("BMP280 init done.\r\n");
    }
    slSPI_Init();
    slNRF24_IoInit();
    setupTimer();
    setupInt1();
    slNRF24_Init();
    slADC_init();
    sei();
    stage = 10;

    while (1) {
        switch (stage) {
            case 10:
                goReset();
                stage = 0;
                break;
            case 12://get measures
                getMesurements(&BME180measure);
                stage = 0;
                break;
        }
    }
    return 0;
}


void setupTimer() {
    TCCR0 |= (1 << CS02) | (1 << CS00);//prescaler 1024
    TIMSK |= (1 << TOIE0);//przerwanie przy przepłnieniu timera0
}

void setupResetPin(){
    DDRD |= (1 << DDD7);//set DDD7 as output
    PORTD &= ~(1 << DDD7);// set as 0
}

void setupInt1() {
    DDRD &= ~(1 << DDD3);     // Clear the PD2 pin
    // PD2 (PCINT0 pin) is now an input
    PORTD |= (1 << PORTD3);    // turn On the Pull-up
    // PD2 is now an input with pull-up enabled
    MCUCR |= (1 << ISC11);// INT0 falling edge PD2
    MCUCR &= ~(1 << ISC10);// INT0 falling edge PD2
    GICR |= (1 << INT1);     // Turns on INT0
}


ISR(TIMER0_OVF_vect) {
    //co 0.032768sek.
    counter = counter + 1;
    if (counter == 200) {//6.55 sek Next mesurements
        counter = 0;
        stage = 12;//make measure
    }
    isTimeoutError = isTimeoutError + 1;
    if (isTimeoutError >= 1250) {//40.96 sek after reset
        counter = 0;
        errors = errors + 1;
        isTimeoutError = 0;
        slUART_WriteStringNl("Sensor12 FAIL");
        if (errors > 3) {
            restart();
            errors = 0;
            stage = 0;
        }
    }
}

ISR(INT1_vect) {
    status = 0;
    counter = 0;
    slNRF24_GetRegister(STATUS, &status, 1);
    cli();
    if ((status & (1 << 6)) != 0) {//got data
        getDataFromNRF24L01(dataFromNRF24L01);
        if (isStartStringMatch(dataFromNRF24L01)) {
            slUART_WriteStringNl("Sensor12 got start command from nRF24L01");
            fillBuferFromMEASURE(&BME180measure, buffer);
            sendVianRF24L01(buffer);
            stage = 0;
        } else {
            slUART_WriteStringNl("Sensor12 got false command from nRF24L01");
            stage = 10;
        }
    }
    if ((status & (1 << 5)) != 0) {//send ok
        stage = 0;
        errors = 0;
        isTimeoutError = 0;
        slUART_WriteStringNl("Sensor12 sent data via nRF24L01 without errors");
    }
    sei();
}
