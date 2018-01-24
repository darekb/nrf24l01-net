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
#include "slSPI.h"


uint8_t status = 0;
volatile uint8_t error = 0;

void setupInt1();

int main(void) {
    slUART_SimpleTransmitInit();
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
    slUART_WriteStringNl("ok:");
    cli();
    status = 0;
    slNRF24_CE_LOW();
    slNRF24_GetRegister(STATUS, &status, 1);
    slUART_WriteString("Sensor21 Status:");
    slUART_LogBinaryNl(status);
    if ((status & (1 << 6)) != 0) {//got data
        slUART_WriteStringNl("Sensor21 got data");
        getDataFromNRF24L01();
        getMesurements();
        sendVianRF24L01();
    }
    if ((status & (1 << 5)) != 0) {//send ok
        #if showDebugDataMain == 1
        slUART_WriteStringNl("Sensor21 OK sent data");
        #endif
        error = 0;
        resetAfterSendData();
    }
   if ((status & (1 << 4)) != 0) {//send failed
       #if showDebugDataMain == 1
       slUART_WriteStringNl("Sensor21 FAIL sent data");
       #endif
       slNRF24_Reset();
       slNRF24_Clear_MAX_RT();
       error = error +1;
       if(error < 7){
           sendVianRF24L01();
       } else {
           error = 0;
           slUART_WriteStringNl("Sensor21 GIVE UP sending data");
       }
   }
    sei();
}
