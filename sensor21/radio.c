//
// Created by dariusz on 03.04.19.
//

#include "radio.h"
#include "NRF24L01/slNRF24.h"

#define COMMAND_PAYLOAD_SIZE 9
#define DATA_PAYLOAD_SIZE 17

uint8_t commandFromNRF24L01[COMMAND_PAYLOAD_SIZE] = {'s', 't', 'a', 'r', 't', '-', 's', '2', '1'};;
uint8_t dataFromNRF24L01[17];

void clearData() {
  for (uint8_t i = 0; i < DATA_PAYLOAD_SIZE; i++) {
    dataFromNRF24L01[i] = 0;
  }
}

void clearCommand() {
  for (uint8_t i = 0; i < COMMAND_PAYLOAD_SIZE; i++) {
    commandFromNRF24L01[i] = 0;
  }
}

char *getCommandFromRadio() {
  clearCommand();
  slNRF24_GetRegister(R_RX_PAYLOAD, commandFromNRF24L01, COMMAND_PAYLOAD_SIZE);
  slNRF24_Reset();
  return (char *) &commandFromNRF24L01;
}
uint8_t *getDataFromRadio() {
  clearData();
  slNRF24_GetRegister(R_RX_PAYLOAD, commandFromNRF24L01, DATA_PAYLOAD_SIZE);
  slNRF24_Reset();
  return (uint8_t *) &dataFromNRF24L01;
}
void sentDataViaRadio(void *data, uint8_t dataSize) {
  slNRF24_SetPayloadSize(DATA_PAYLOAD_SIZE);
  slNRF24_FlushTx();
  slNRF24_FlushRx();
  slNRF24_TxPowerUp();
  slNRF24_TransmitPayload(data, dataSize);
}
void initRadio() {
  slNRF24_IoInit();
  slNRF24_Init();
  slNRF24_PowerDown();
  slNRF24_FlushTx();
  slNRF24_FlushRx();
  slNRF24_Reset();
  slNRF24_RxPowerUp();
  slNRF24_SetPayloadSize(COMMAND_PAYLOAD_SIZE);
  //_delay_ms(10);
}
void afterSendDataViaRadio() {
  slNRF24_FlushRx();
  slNRF24_FlushTx();
  slNRF24_SetPayloadSize(COMMAND_PAYLOAD_SIZE);
  slNRF24_RxPowerUp();
  slNRF24_Reset();
}




