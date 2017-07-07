/*
 * slUart.h
 *
 *  Created on: 12-04-2016
 *      Author: db
 */

#ifndef SLUART_H_
#define SLUART_H_


#ifndef F_CPU
#define F_CPU 16000000UL
#endif
//#define UART_BAUD 9600
#define UART_BAUD 38400
//#define UART_BAUD 115200
#define __UBRR ((F_CPU + UART_BAUD * 8UL) / (16UL * UART_BAUD )-1)

void slUART_Init();

void slUART_SimpleTransmitInit();

void slUART_WriteByte(char data);

void slUART_WriteString(const char myString[]);

void slUART_WriteStringNl(const char myString[]);

void slUART_WriteBuffer(const uint8_t myData[], uint8_t length);

void slUART_LogBinary(uint16_t dataIn);

void slUART_LogBinaryNl(uint16_t dataIn);

void slUART_LogDec(uint16_t dataIn);

void slUART_LogDecWithSign(int16_t dataIn);

void slUART_LogDecNl(uint16_t dataIn);

void slUART_LogHex(uint16_t dataIn);

void slUART_LogHexNl(uint16_t dataIn);

#endif /* SLUART_H_ */
