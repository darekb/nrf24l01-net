#ifndef F_CPU
// A reasonable default clock speed
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include "slUart.h"
#include <sim_avr.h>
#include <sim_gdb.h>

/*
 * This demonstrate how to use the avr_mcu_section.h file
 * The macro adds a section to the ELF file with useful
 * information for the simulator
 */
#include "avr_mcu_section.h"

AVR_MCU(F_CPU, "atmega328");

// Basic Bitwise Functions
#define SET_LOW(port, pin)  port &= ~_BV(pin)
#define SET_HIGH(port, pin) port |=  _BV(pin)
#define TOGGLE(port, pin)   port ^=  _BV(pin)

const struct avr_mmcu_vcd_trace_t _mytrace[]
_MMCU_ = {
    { AVR_MCU_VCD_SYMBOL("PORTB"), .what = (void*)&PORTB, },
    //{AVR_MCU_VCD_SYMBOL("PB5"), .mask = _BV(PB5), .what = (void *) &PORTB},
};


#define ST_START 1
#define ST_GOT_DATA 2
#define ST_SENT_DATA 3
#define ST_ERROR_SENT_DATA 4
#define ST_UNKNOWN_ERROR 5
#define ST_WAITING 0

uint8_t status;
volatile uint8_t stage = 0;
volatile uint8_t recieviedResponse = 0;

volatile uint16_t counter = 0;
//counter for next mesure
volatile uint16_t counter2 = 0;
//counter for reset mesurements
volatile uint16_t counter3 = 0;

//counter for fail response form sensor
int main(void) {
    DDRB = 0xff;//set DDD7 as output
    PORTB = 0x00;
    TCCR0B |= (1 << CS02) | (1 << CS00);//prescaler 1024
    TIMSK0 |= (1 << TOIE0);//przerwanie przy przepłnieniu timera0
    sei();
    stage = ST_START;
    while (1) {
        if(stage == ST_START){
          PORTB = 0x00;
          TOGGLE(PORTB, stage);
          stage = ST_WAITING;
        }
        if(stage == ST_SENT_DATA){
          PORTB = 0x00;
          TOGGLE(PORTB, stage);
          _delay_ms(1);
          stage = ST_GOT_DATA;
        }
        if(stage == ST_GOT_DATA){
          PORTB = 0x00;
          TOGGLE(PORTB, stage);
          stage = ST_START;
        }
        if(stage == ST_ERROR_SENT_DATA){
          PORTB = 0x00;
          TOGGLE(PORTB, stage);
          stage = ST_WAITING;
        }
        if(stage == ST_UNKNOWN_ERROR){
          PORTB = 0x00;
          TOGGLE(PORTB, stage);
          stage = ST_WAITING;
        }
      }
      return 0;
    }



ISR(TIMER0_OVF_vect) {
    //co 0.01632sek.
    if (stage == ST_WAITING) {
        counter = counter + 1;
    } else {
        counter2 = counter2 + 1;
    }
    if (counter == 5) {//17.952 sek Next mesurements
        //counter = 0;
        stage = ST_SENT_DATA;
    }
    if (counter == 6) {//46.348 sek Reset to sending
        //counter = 0;
        stage = ST_UNKNOWN_ERROR;
    }
    if (counter == 7) {//46.348 sek Reset to sending
        counter = 0;
        stage = ST_ERROR_SENT_DATA;
    }
}



/*
make all
make sim
*/

/*
https://www.easycalculation.com/engineering/electrical/avr-timer-calculator.php
f = cf / p
o = ttt / tr2
rtt = t - (o * tr2)
rt = ttt / f
nf = f / ttt

Where, f = Frequency
cf = System Clock Frequency
p = Prescaler Clock Value
o =Overflow Count
tr = Timer Resolution
ttt = Total Timer Ticks
rtt = Remainder Timer Ticks
rt = Real Time
nf = New Frequency
*/