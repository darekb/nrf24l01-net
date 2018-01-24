#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#define showDebugDataMain 1

#if showDebugDataMain == 1

#include "slUart.h"

#endif

#include "main.h"
#include "slNRF24.h"
#include "main_functions.h"

#define LED (1 << PB0)
#define LED_TOG PORTB ^= LED

void setupInt0();

volatile uint8_t error = 0;

int main(void) {
    _delay_ms(500);
    slUART_SimpleTransmitInit();
    #if showDebugDataMain == 1
    slUART_WriteStringNl("Start server");
    DDRB |= (1 << DDB0);//set DDD7 as output
    PORTB &= ~(1 << DDB0);// set as 0
    #endif
    setupInt0();
    sei();
    initAll();
    while (1) {
        if(!error || error > 40) {
            error = 0;
            nextSensorNr();
        }
        sendCommandToSensor();
        for(uint8_t i =0; i<2; i++){
            _delay_ms(1000);
        }
    }
    return 0;
}

void setupInt0() {
    DDRD &= ~(1 << DDD2);     // Clear the PD2 pin
    // PD2 (PCINT0 pin) is now an input
    PORTD |= (1 << PORTD2);    // turn On the Pull-up
    // PD2 is now an input with pull-up enabled
    EICRA |= (1 << ISC01);// INT0 falling edge    PD2
    EICRA &= ~(1 << ISC00);// INT0 falling edge PD2
    EIMSK |= (1 << INT0);     // Turns on INT0
}



ISR(INT0_vect) {
    uint8_t status = 0;
    //cli();
    slNRF24_CE_LOW();
    slNRF24_GetRegister(STATUS, &status, 1);
    slUART_WriteString("SERVER Status:");
    slUART_LogBinaryNl(status);
    slNRF24_Reset();
    if ((status & (1 << 4)) != 0) {//send failed
        saveErrorData();
        #if showDebugDataMain == 1
        slUART_WriteStringNl("Server FAIL sent data");
        #endif
        slNRF24_Reset();
        //slNRF24_Clear_MAX_RT();
        error = error + 1;
//        sendCommandToSensor();
//        sei();
//        _delay_ms(200);
    }
    if ((status & (1 << 6)) != 0) {
        #if showDebugDataMain == 1
        slUART_WriteStringNl("Server got data ");
        #endif
        saveDataFromNRF();
    }
    if ((status & (1 << 5)) != 0) {//send ok
        #if showDebugDataMain == 1
        LED_TOG;
        slUART_WriteStringNl("Server OK sent ok ");
        #endif
        error = 0;
        resetAfterSendData();
    }
    sei();
}