#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#define showDebugDataMain 0

#include "slUart.h"

#include "main.h"
#include "slNRF24.h"
#include "main_functions.h"
#include "slSPI.h"
#include "slI2C.h"
#include "slPCF8563.h"

#define LED (1 << PB0)
#define LED_TOG PORTB ^= LED

#define ST_START 1
#define ST_GOT_DATA 2
#define ST_SENT_DATA 3
#define ST_ERROR_SENT_DATA 4
#define ST_UNKNOWN_ERROR 5
#define ST_END_STATE 6
#define ST_WAITING 0

void setupTimer0();
void setupInt1();

uint8_t status;
volatile uint8_t stage = 0;
volatile uint16_t counter = 0;

int main(void) {
  slUART_SimpleTransmitInit();
  slUART_WriteStringNl("Start server");
  setupTimer0();
  setupInt1();
  slSPI_Init();
  slI2C_Init();
  slNRF24_IoInit();
  slNRF24_Setup();
  nRF24L01Start();
  slNRF24_Reset();
  PCF8563Start();
  nextSensorNr();
  stage = ST_START;
  while (1) {
    if (stage == ST_START) {
      cli();
      sensorStart();
      stage = ST_WAITING;
      sei();
    }
    if (stage == ST_SENT_DATA) {
      cli();
      #if showDebugDataMain == 1
      slUART_WriteStringNl("server sent ok ");
      #endif
      resetNRF24L01p();
      //_delay_ms(1);
      stage = ST_WAITING;
      sei();
    }
    if (stage == ST_GOT_DATA) {
      cli();
      #if showDebugDataMain == 1
      slUART_WriteStringNl("server got data ");
      #endif
      saveDataFromNRF();
      resetNRF24L01p();
      //_delay_ms(1);
      stage = ST_END_STATE;
      sei();
    }
    if (stage == ST_ERROR_SENT_DATA) {
      cli();
      #if showDebugDataMain == 1
      slUART_WriteStringNl("Server FAIL data");
      #endif
      saveErrorData();
      if (returnCountErrorsForSensor() > 7) {
        stage = ST_END_STATE;
      } else {
        stage = ST_START;
      }
      resetNRF24L01p();
      _delay_ms(2000);
      stage = ST_END_STATE;
      sei();
    }
    if (stage == ST_UNKNOWN_ERROR) {
      cli();
      #if showDebugDataMain == 1
      slUART_WriteStringNl("Server unknown error");
      #endif
      saveErrorData();
      if (returnCountErrorsForSensor() > 7) {
        stage = ST_END_STATE;
      } else {
        stage = ST_START;
      }
      resetNRF24L01p();
      _delay_ms(1000);
      sei();
    }
    if (stage == ST_END_STATE) {
      if (ifCheckEverySensor()) {
        resetErrors();
        stage = ST_WAITING;
        sendingSensorDataViaUart();
        #if showDebugDataMain == 1
        slUART_WriteStringNl("------------");
        #endif
      } else {
        stage = ST_START;
      }
      nextSensorNr();
    }
  }
  return 0;
}

void setupTimer0() {
  TCCR0B |= (1 << CS02) | (1 << CS00);//prescaler 1024
  TIMSK0 |= (1 << TOIE0);//przerwanie przy przepłnieniu timera0
}
void setupTimer1() {
  TCCR1A |= ((1<<CS10) & ~(1<<CS11) & ~(1<<CS12) );//prescaler 1
  TIMSK1 |= (1 << TOIE0);//przerwanie przy przepłnieniu timera1
}

void setupInt1() {
  DDRD &= ~(1 << PD3);     // Clear the PD3 pin
  // PD2 (PCINT0 pin) is now an input
  PORTD |= (1 << PD3);    // turn On the Pull-up
  // PD2 is now an input with pull-up enabled
  EICRA |= (1 << ISC11);// INT1 falling edge    PD3
  EICRA &= ~(1 << ISC10);// INT1 falling edge PD3
  EIMSK |= (1 << INT1);     // Turns on INT1
}

ISR(INT1_vect) {
  status = 0;
  slNRF24_GetRegister(STATUS, &status, 1);
  #if showDebugDataMain == 1
  slUART_WriteString("Server STATUS:");
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
  //co 0.03264sek.
  if (stage == ST_WAITING) {
    counter = counter + 1;
  }
  if (counter >= 1230) {//40.1472 sek Next mesurements
    counter = 0;
    stage = ST_START;
  }
}
