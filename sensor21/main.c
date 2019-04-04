#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#define showDebugDataMain 1

#include "main.h"
#if showDebugDataMain == 1
#include "slUart.h"
#endif

#include "slNRF24.h"
#include "main_functions.h"
#include "slSPI.h"
#include "slI2C.h"
#include "BME280.h"
#include "slAdc.h"
#include "sensors.h"
#include "radio.h"


#define ST_START 1
#define ST_GOT_DATA 2
#define ST_SENT_DATA 3
#define ST_ERROR_SENT_DATA 4
#define ST_UNKNOWN_ERROR 5
#define ST_END_STATE 6
#define ST_GET_MEASURE 7
#define ST_TIMEOUT 8
#define ST_WAITING 0

void setupResetPin();

void setupTimer();

void setupInt1();


uint8_t status;
volatile uint8_t stage = 0;
volatile uint8_t errors = 0;
volatile uint16_t counter = 0;
volatile uint16_t isTimeoutError = 0;

int main(void) {
    #if showDebugDataMain == 1
    slUART_SimpleTransmitInit();
    slUART_WriteStringNl("Start sensor21");
    #endif
    slI2C_Init();
    if (BME280_Init(BME280_OS_T_SKP, BME280_OS_P_SKP, BME280_OS_H_SKP, BME280_FILTER_OFF, BME280_MODE_FORCED,
                    BME280_TSB_1000)) {
        #if showDebugDataMain == 1
        slUART_WriteString("BMP280 init error.\r\n");
        #endif
    } else {
        #if showDebugDataMain == 1
        slUART_WriteString("BMP280 init done.\r\n");
        #endif
    }
    setupResetPin();
    setupTimer();
    setupInt1();
    slSPI_Init();
    slNRF24_IoInit();
    slNRF24_Init();
    resetNRF24L01();
    slADC_init();
    initADCData();
    sei();
    stage = ST_WAITING;
    while (1) {
        if (stage == ST_SENT_DATA) {
            cli();
            #if showDebugDataMain == 1
            slUART_WriteStringNl("Sensor21 sent data");
            #endif
            resetAfterSendData();
            stage = ST_WAITING;
            sei();
        }
        if (stage == ST_GOT_DATA) {
            cli();
            getDataFromNRF24L01();
            if (isStartStringMatch()) {
                #if showDebugDataMain == 1
                slUART_WriteStringNl("Sensor21 got start command from nRF24L01");
                #endif
                prepeareBuffer();
                //_delay_ms(100);
                sendVianRF24L01();
            } else {
                #if showDebugDataMain == 1
                slUART_WriteStringNl("Sensor21 got false command from nRF24L01");
                #endif
            }
            stage = ST_WAITING;
            sei();
        }
        if (stage == ST_ERROR_SENT_DATA) {
            cli();
            #if showDebugDataMain == 1
            slUART_WriteStringNl("Sensor21 FAIL data");
            #endif
            resetAfterSendData();
            stage = ST_WAITING;
            sei();
        }
        if (stage == ST_UNKNOWN_ERROR) {
            cli();
            #if showDebugDataMain == 1
            slUART_WriteStringNl("Sensor21 unknow error");
            #endif
            //slNRF24_PrintRegisters();
            resetAfterSendData();
            stage = ST_WAITING;
            sei();
        }
        if (stage == ST_GET_MEASURE) {
            getMesurements();
            stage = ST_WAITING;
        }
        if (stage == ST_TIMEOUT) {
            #if showDebugDataMain == 1
            slUART_WriteStringNl("Sensor21 FAIL");
            #endif
            resetNRF24L01();
            if (errors > 3) {
                restart();
                errors = 0;
                stage = 0;
            }
            stage = ST_WAITING;
        }

    }
    return 0;
}

void setupResetPin() {
    DDRD |= (1 << DDD7);//set DDD7 as output
    PORTD &= ~(1 << DDD7);// set as 0
}

void setupTimer() {
    TCCR0 |= (1 << CS02) | (1 << CS00);//prescaler 1024
    TIMSK |= (1 << TOIE0);//przerwanie przy przepłnieniu timera0
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


ISR(INT1_vect) {
    status = 0;
    slNRF24_CE_LOW();
    slNRF24_GetRegister(STATUS, &status, 1);
    #if showDebugDataMain == 1
    slUART_WriteString("Sensor21 STATUS:");
    slUART_LogBinaryNl(status);
    #else
    _delay_ms(100);
    #endif
    if ((status & (1 << 5)) != 0) {
        stage = ST_SENT_DATA;
    }
    if ((status & (1 << 6)) != 0) {
        stage = ST_GOT_DATA;
    }
    if ((status & (1 << 4)) != 0) {
        stage = ST_ERROR_SENT_DATA;
    }
    if (status == 0xE) {
        stage = ST_UNKNOWN_ERROR;
    }
}


ISR(TIMER0_OVF_vect) {
    //co 0.032768sek.
    counter = counter + 1;
    if (counter > 100) {//3.27 sek Next mesurements
        counter = 0;
        stage = ST_GET_MEASURE;//make measure
    }
    isTimeoutError = isTimeoutError + 1;
    if (isTimeoutError >= 2500) {//40.96 sek after reset
        counter = 0;
        errors = errors + 1;
        isTimeoutError = 0;
        stage = ST_TIMEOUT;
    }
}