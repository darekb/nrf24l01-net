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
#include "slSPI.h"


#define LED (1 << PB0)
#define LED_TOG PORTB ^= LED

void setupInt0();

uint8_t status;
uint8_t recieviedResponse = 0;

//counter for fail response form sensor
int main(void) {
    slUART_SimpleTransmitInit();
    //slUART_Init();
    slUART_WriteStringNl("Start server");
    setupInt0();
    sei();
    slSPI_Init();
    slNRF24_IoInit();
    nRF24L01Start();
    slNRF24_Reset();
    nextSensorNr();
    while (1) {
        if(recieviedResponse > 0){
            recieviedResponse = 0;
            nextSensorNr();
        }
        if(recieviedResponse == 5){
            recieviedResponse = 0;
            nextSensorNr();
        }
        sensorStart();
        for(uint8_t i =0; i<1; i++){
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
    status = 0;
    slNRF24_CE_LOW();
    slNRF24_GetRegister(STATUS, &status, 1);
    #if showDebugDataMain == 1
    slUART_WriteString("Server STATUS:");
    slUART_LogBinaryNl(status);
    #endif
    cli();
    if(status == 0xE){
        slNRF24_PrintRegisters();
        resetAfterSendData();
    }
    if ((status & (1 << 6)) != 0) {
        recieviedResponse = 1;
        #if showDebugDataMain == 1
        slUART_WriteStringNl("server got data ");
        #endif
        saveDataFromNRF();
        resetAfterSendData();
        _delay_ms(1);
    }
    if ((status & (1 << 5)) != 0) {//send ok
        recieviedResponse = 0;
        #if showDebugDataMain == 1
        slUART_WriteStringNl("server sent ok ");
        #endif
        resetAfterSendData();
        _delay_ms(1);
    }
    if ((status & (1 << 4)) != 0) {//send fail
        recieviedResponse = recieviedResponse + 1;
        #if showDebugDataMain == 1
        slUART_WriteStringNl("Server FAIL data");
        #endif
        resetAfterSendData();
        _delay_ms(1);
    }
    sei();
}