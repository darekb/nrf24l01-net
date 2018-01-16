#include <avr/io.h>
#include <avr/interrupt.h>


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

void setupInt1();

int main(void) {
    #if showDebugDataMain == 1
    slUART_SimpleTransmitInit();
    slUART_WriteString("start.\r\n");
    #endif
    slNRF24_IoInit();
    setupInt1();
    slNRF24_Init();
    sei();
    while (1) {}
    return 0;
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
    uint8_t status = 0;
    slNRF24_GetRegister(STATUS, &status, 1);
    cli();
    if ((status & (1 << 6)) != 0) {//got data
        getDataFromNRF24L01();
        slUART_WriteStringNl("Sensor21 got data");
        getMesurements();
        prepeareBuffer();
        sendVianRF24L01();
    }
    if ((status & (1 << 5)) != 0) {//send ok
        #if showDebugDataMain == 1
        slUART_WriteStringNl("Sensor21 sent data");
        #endif
    }
    sei();
}
