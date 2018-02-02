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

void setupInt1();

int main(void) {
    slUART_SimpleTransmitInit();
    //slUART_Init();
    slUART_WriteStringNl("Start sensor21");
    setupInt1();
    sei();
    slSPI_Init();
    slNRF24_IoInit();
    slNRF24_Init();
    resetNRF24L01();
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
    slNRF24_CE_LOW();
    slNRF24_GetRegister(STATUS, &status, 1);
    slUART_WriteString("Sensor21 STATUS:");
    slUART_LogBinaryNl(status);
    cli();
    if(status == 0xE){
        slNRF24_PrintRegisters();
        resetAfterSendData();
    }
    if ((status & (1 << 6)) != 0) {//got data
        getDataFromNRF24L01();
        slUART_WriteStringNl("Sensor21 got data");
        getMesurements();
        _delay_ms(100);
        sendVianRF24L01();
    }
    if ((status & (1 << 5)) != 0) {//send ok
        #if showDebugDataMain == 1
        slUART_WriteStringNl("Sensor21 sent data");
        #endif
        resetAfterSendData();
    }
    if ((status & (1 << 4)) != 0) {//send fail
        #if showDebugDataMain == 1
        slUART_WriteStringNl("Sensor21 FAIL data");
        #endif
        resetAfterSendData();
    }
    sei();
}
