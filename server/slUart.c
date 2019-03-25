/*
 * slUart.c
 *
 *  Created on: 12-04-2016
 *      Author: db
 */
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include <string.h>
#include "slUart.h"

void slUART_SimpleTransmitInit() {
  UBRRH = (uint16_t) (__UBRR >> 8);
  UBRRL = (uint8_t) __UBRR;
  /* Enable transmitter */
  UCSRB = (1 << TXEN);
  //reszta jest domyślnie ustawiona po resecie
}

void slUART_Init() {
  slUART_SimpleTransmitInit();
  //Enable receiver
  //UCSRB |= (1 << RXEN);
  UCSRC = (1 << USBS) | (3 << UCSZ0);
  //UCSRC = (3 << UCSZ0) & ~(1 << USBS);
}

void slUART_WriteByte(char data) {
  while (!(UCSRA & (1 << UDRE))) {
  }
  UDR = data;
}

void slUART_WriteString(const char myString[]) {
  uint8_t i = 0;
  while (myString[i]) {
    slUART_WriteByte(myString[i]);
    i++;
  }
}

void slUART_WriteStringNl(const char myString[]) {
  slUART_WriteString(myString);
  slUART_WriteString("\r\n");
}

void slUART_WriteBuffer(uint8_t *myData, uint8_t length) {
  slUART_WriteBufferHex(myData, length);
}
void slUART_WriteBufferHex(uint8_t *myData, uint8_t length) {
  for (uint8_t i = 0; i < length; i++) {
    slUART_LogHex((uint8_t) myData[i]);
    slUART_WriteByte(' ');
  }
  slUART_WriteString("\r\n");
}
void slUART_WriteBufferBin(uint8_t *myData, uint8_t length) {
  for (uint8_t i = 0; i < length; i++) {
    slUART_LogBinary((uint8_t) myData[i]);
    slUART_WriteByte(' ');
  }
  slUART_WriteString("\r\n");
}

void slUART_LogBinary(uint16_t dataIn) {
  char buff[30];
  itoa(dataIn, buff, 2);
  slUART_WriteString(buff);
}

void slUART_LogBinaryNl(uint16_t dataIn) {
  slUART_LogBinary(dataIn);
  slUART_WriteString("\r\n");
}

void slUART_LogDec(uint16_t dataIn) {
  char buff[30];
  itoa(dataIn, buff, 10);
  slUART_WriteString(buff);
}

void slUART_LogDecWithSign(int16_t dataIn) {
  char buff[30];
  itoa(dataIn, buff, 10);
  slUART_WriteString(buff);
}

void slUART_LogDecNl(uint16_t dataIn) {
  slUART_LogDec(dataIn);
  slUART_WriteString("\r\n");
}

void slUART_LogHex(uint16_t dataIn) {
  char buff[30];
  itoa(dataIn, buff, 16);
  slUART_WriteString(buff);
}

void slUART_LogHexNl(uint16_t dataIn) {
  slUART_LogHex(dataIn);
  slUART_WriteString("\r\n");
}

void slUART_LogHex32WithSign(int32_t dataIn) {
  char buff[16];
  ltoa(dataIn, buff, 16);
  slUART_WriteString(buff);
}
void slUART_LogHex32(uint32_t dataIn) {
  char buff[16];
  ltoa(dataIn, buff, 16);
  slUART_WriteString(buff);
}
