/*
 * slAdc.h
 *
 *  Created on: 14-04-2016
 *      Author: db
 */

#ifndef SLADC_H_
#define SLADC_H_

#define REF_256 (1<<REFS1)|(1<<REFS0) //11
#define REF_VCC (1<<REFS0) & ~(1<<REFS1) //10
#define PRESCALER_16 (1<<ADPS2) & ~(1<<ADPS1) & ~(1<<ADPS0) //100 Przy 8MHz oscylatora daje to 500kHz czyli poza zakresem na które producent pozwala. 
#define PRESCALER_128 (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0)  //111 //dobry prescaler bo się mieści w zakresach podaych w nocie katalogowej


#define SR 16 //ilośc próbek przy uśrednianiu pomiaru dajemy potęgi 2 bo uzywamy maskowania

typedef struct {
  uint16_t adc_mid;
  uint16_t sr[SR];//tablica z wartoścami do średniej wleczonej
  uint8_t idx;//index średniej wleczonej
} TVOL;

void slADC_init();
uint16_t slADC_measure(uint8_t pin);
void slADC_initializeData(TVOL * voltage);
void slADC_calculateVol(uint16_t adc, TVOL * voltage);

#endif /* SLADC_H_ */
