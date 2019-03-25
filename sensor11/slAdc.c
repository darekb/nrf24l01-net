/*
 * slAdc.c
 *
 *  Created on: 14-04-2016
 *      Author: db
 */
#include <avr/io.h>
#include <stdlib.h>
#include "slAdc.h"



void slADC_init() {
	ADCSRA |= (1 << ADEN); //włącz ADC
	ADCSRA |= PRESCALER_128; //dobry preskaler
	ADMUX |= REF_256; //ustawiamy wewn. źródłó
}

uint16_t slADC_measure(uint8_t pin) {
	ADMUX = (ADMUX & 0xf8); // 0b11111000 Zerujemy trzy starse bity
	ADMUX = ADMUX | pin; // Co jest równoznaczne z zapisem ADMUX = ADMUX | (1<<MUX2) | (1<<MUX0); dla pinu PC5
	//my korzysamy z tego że wartości trzech starsze bitow tego rejestru odpowiadają zapisowi bitowego kolejnych portów
	//rejestru PCn
	ADCSRA |= (1 << ADSC); //start konwersji
	while (ADCSRA & (1 << ADSC)) {
	} //czekamy aż się skończy pomiar
	return ADCW; //zwracamy pomiar (korzystając z wbudowanego makra)
}

void slADC_initializeData(TVOL * voltage){
	uint8_t i = 0;
	voltage->idx = 0;
	for (i = 0; i < SR; i++) {
		voltage->sr[i] = 0;
	}
	voltage->adc_mid = 0;
}

void slADC_calculateVol(uint16_t adc, TVOL * voltage) {
	uint16_t sr1 = 0;
	uint8_t i = 0;
	voltage->sr[voltage->idx++ & (SR - 1)] = adc; //& (SR-1) = maskowanie
	for (i = 0; i < SR; i++) {
		sr1 = sr1 + voltage->sr[i];
	}
	voltage->adc_mid = sr1;
}
