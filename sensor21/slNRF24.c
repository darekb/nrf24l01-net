#include <avr/io.h>
#include <util/delay.h>

#include "slNRF24.h"
#include "slSPI.h"

#if showDebugDataSlnRF24 == 1
#include "slUart.h"
#endif


void slNRF24_IoInit(void) {
  CSN_OUTPUT();
  CE_OUTPUT();
  CSN_HIGH();
  CE_LOW();
}

void slNRF24_SetRegister(uint8_t reg, void *dataIn, uint8_t len) {
  uint8_t *data = dataIn;
  _delay_us(10);
  CSN_LOW();
  _delay_us(10);
  slSPI_TransferInt(W_REGISTER + reg);
  _delay_us(10);
  for (uint8_t i = 0; i < len; i++) {
    slSPI_TransferInt(data[i]);
    _delay_us(10);
  }
  CSN_HIGH();
}

void slNRF24_GetRegister(uint8_t reg, uint8_t *dataIn, uint8_t len) {
  _delay_us(10);
  CSN_LOW();
  _delay_us(10);
  slSPI_TransferInt(R_REGISTER + reg);
  _delay_us(10);
  for (uint8_t i = 0; i < len; i++) {
    dataIn[i] = slSPI_TransferInt(0x00);
    _delay_us(10);
  }
  CSN_HIGH();
}

void slNRF24_SetReadingAddress(const uint8_t pipeNr, uint8_t adress, uint8_t payloadSize) {
  _delay_ms(100);
  uint8_t val[5] = {0xB3, 0xB3, 0xB3, 0xB3, 0x00};
  val[4] = adress;
  uint8_t rxReg = 0;
  uint8_t rxPwReg = 0;
  switch(pipeNr){
    default:
      rxReg = RX_ADDR_P1;
      rxPwReg = RX_PW_P1;
      break;
    case 1:
      rxReg = RX_ADDR_P1;
      rxPwReg = RX_PW_P1;
      break;
    case 2:
      rxReg = RX_ADDR_P2;
      rxPwReg = RX_PW_P2;
      break;
    case 3:
      rxReg = RX_ADDR_P3;
      rxPwReg = RX_PW_P3;
      break;
    case 4:
      rxReg = RX_ADDR_P4;
      rxPwReg = RX_PW_P4;
      break;
    case 5:
      rxReg = RX_ADDR_P5;
      rxPwReg = RX_PW_P5;
      break;
  }
  slNRF24_SetRegister(rxReg, val, 5);
  slNRF24_SetRegister(rxPwReg, &payloadSize, 1);
  val[0] = 0x3f;
  slNRF24_SetRegister(EN_RXADDR, val, 1);
}


void slNRF24_OpenWritingPipe(const uint8_t *address, uint8_t payloadSize) {
  slNRF24_SetRegister(RX_ADDR_P0, (uint8_t *)address, 5);
  slNRF24_SetRegister(TX_ADDR, (uint8_t *)address, 5);
  slNRF24_SetRegister(RX_PW_P0, &payloadSize, 1);
}
void slNRF24_OpenReadingPipe(uint8_t child, const uint8_t *address, uint8_t payloadSize) {
  uint8_t rxReg = 0;
  uint8_t rxPwReg = 0;
  switch(child){
    default:
      rxReg = RX_ADDR_P1;
      rxPwReg = RX_PW_P1;
      break;
    case 1:
      rxReg = RX_ADDR_P1;
      rxPwReg = RX_PW_P1;
      break;
    case 2:
      rxReg = RX_ADDR_P2;
      rxPwReg = RX_PW_P2;
      break;
    case 3:
      rxReg = RX_ADDR_P3;
      rxPwReg = RX_PW_P3;
      break;
    case 4:
      rxReg = RX_ADDR_P4;
      rxPwReg = RX_PW_P4;
      break;
    case 5:
      rxReg = RX_ADDR_P5;
      rxPwReg = RX_PW_P5;
      break;
  }
  slNRF24_SetRegister(rxReg, (uint8_t *)address, 5);
  slNRF24_SetRegister(rxPwReg, &payloadSize, 1);
  uint8_t val = 0x3f;
  uint8_t *v = &val;
  slNRF24_SetRegister(EN_RXADDR, v, 1);
}


void slNRF24_SetWritingAddress(uint8_t adress, uint8_t payloadSize) {
  _delay_ms(100);
  uint8_t val[5] = {0xB3, 0xB3, 0xB3, 0xB3, 0x00};
  val[4] = adress;
  slNRF24_SetRegister(RX_ADDR_P0, val, 5);
  slNRF24_SetRegister(TX_ADDR, val, 5);
  slNRF24_SetRegister(RX_PW_P0, &payloadSize, 1);
}

void slNRF24_Init(void) {
  _delay_ms(1000);    //allow radio to reach power down if shut down
  uint8_t val[5];

  //SETUP_RETR (the setup for "EN_AA") 4000uS 15 retransmit
  val[0] =
      0xFF;    //0b0010 00011 "2" sets it up to 750uS delay between every retry (at least 500us at 250kbps and if payload >5bytes in 1Mbps, and if payload >15byte in 2Mbps) "F" is number of retries (1-15, now 15)
  slNRF24_SetRegister(SETUP_RETR, val, 1);

  //Enable ‘Auto Acknowledgment’ Function on data pipe 0 and pipe 1
  val[0] = 0x07;
  slNRF24_SetRegister(EN_AA, val, 1);

  //enable data pipe 0 for RX
  val[0] = 0x07;
  slNRF24_SetRegister(EN_RXADDR, val, 1);

  //Setup of Address Width = 5 bytes
  val[0] = 0x03;
  slNRF24_SetRegister(SETUP_AW, val, 1);

  //RF channel setup - 2,400-2,527GHz 1MHz/chanel
  val[0] = 127;//2,527Ghz
  slNRF24_SetRegister(RF_CH, val, 1);

  //RF setup	- 1Mbps spped and 0dBm
  val[0] = 0x06;
  slNRF24_SetRegister(RF_SETUP, val, 1);

  //slNRF24_ChangeAddress(SENSOR_ADDR);




  val[0] = PAYLOAD_SIZE;
  slNRF24_SetRegister(RX_PW_P0, val, 1);
  slNRF24_SetRegister(RX_PW_P1, val, 1);

  //CONFIG reg setup - Mask interrupt caused by MAX_RT disabled enable CRC CRC 2 byte scheme power up
  val[0] = 0x0E;
  slNRF24_SetRegister(CONFIG, val, 1);

  slNRF24_SetReadingAddress(0, SENSOR_ADDR, PAYLOAD_SIZE);
  slNRF24_SetWritingAddress(SERVER_ADDR, PAYLOAD_SIZE);

  //device need 1.5ms to reach standby mode
  _delay_ms(100);
}

void slNRF24_SetPayloadSize(uint8_t playloadSize) {
  slNRF24_SetRegister(RX_PW_P0, &playloadSize, 1);
  slNRF24_SetRegister(RX_PW_P1, &playloadSize, 1);
}

void slNRF24_Reset(void) {
  _delay_us(10);
  CSN_LOW();
  _delay_us(10);
  slSPI_TransferInt(W_REGISTER + STATUS);
  _delay_us(10);
  //reset Data Ready RX FIFO interrupt, Data Sent TX FIFO interrupt, Maximum number of TX retransmits interrupt
  slSPI_TransferInt(0x70);
  _delay_us(10);
  CSN_HIGH();
}

void slNRF24_CE_LOW() {
  CE_LOW();
}

void slNRF24_TransmitPayload(void *dataIn, uint8_t len) {
  uint8_t *data = dataIn;
  slNRF24_SetRegister(RX_PW_P0, &len, 1);
  _delay_us(10);
  CSN_LOW();
  _delay_us(10);
  slSPI_TransferInt(W_TX_PAYLOAD);
  _delay_us(10);
  for (uint8_t i = 0; i < len; i++) {
    slSPI_TransferInt(data[i]);
    _delay_us(10);
  }
  CSN_HIGH();
  _delay_ms(10);
  CE_HIGH();
  _delay_us(20);
  CE_LOW();
  _delay_ms(10);
}

void slNRF24_TxPowerUp() {
//  uint8_t configReg;
//  slNRF24_GetRegister(CONFIG, &configReg, 1);
//  configReg |= (1 << PWR_UP);
//  configReg &= ~(1 << PRIM_RX);
//  slNRF24_SetRegister(CONFIG, &configReg, 1);
//  slNRF24_FlushTx();
  CE_LOW();
  slNRF24_FlushRx();
  slNRF24_FlushTx();
}

void slNRF24_RxPowerUp() {
  uint8_t configReg;
  slNRF24_GetRegister(CONFIG, &configReg, 1);
  configReg |= (1 << PWR_UP) | (1 << PRIM_RX);
  slNRF24_SetRegister(CONFIG, &configReg, 1);
  slNRF24_FlushRx();
  slNRF24_FlushTx();
  CE_HIGH();
  _delay_ms(130);
}

void slNRF24_PowerDown() {
  uint8_t configReg;
  slNRF24_GetRegister(CONFIG, &configReg, 1);
  configReg |= (1 << PRIM_RX);
  configReg &= ~(0 << PWR_UP);
  slNRF24_SetRegister(CONFIG, &configReg, 1);
  CE_HIGH();
}

void slNRF24_FlushTx() {
  _delay_us(10);
  CSN_LOW();
  _delay_us(10);
  slSPI_TransferInt(FLUSH_TX);
  _delay_us(10);
  CSN_HIGH();
}

void slNRF24_FlushRx() {
  _delay_us(10);
  CSN_LOW();
  _delay_us(10);
  slSPI_TransferInt(FLUSH_RX);
  _delay_us(10);
  CSN_HIGH();
}


#if showDebugDataSlnRF24 == 1
void slNRF24_PrintRegisters(){
    uint8_t reg[5];
    slNRF24_GetRegister(STATUS, reg, 1);
    slUART_WriteString("STATUS: ");
    slUART_WriteBufferBin(reg, 1);
    slNRF24_GetRegister(SETUP_RETR, reg, 1);
    slUART_WriteString("SETUP_RETR: ");
    slUART_WriteBufferBin(reg, 1);
    slNRF24_GetRegister(EN_AA, reg, 1);
    slUART_WriteString("EN_AA: ");
    slUART_WriteBufferBin(reg, 1);
    slNRF24_GetRegister(EN_RXADDR, reg, 1);
    slUART_WriteString("EN_RXADDR: ");
    slUART_WriteBufferBin(reg, 1);
    slNRF24_GetRegister(SETUP_AW, reg, 1);
    slUART_WriteString("SETUP_AW: ");
    slUART_WriteBufferBin(reg, 1);
    slNRF24_GetRegister(RF_CH, reg, 1);
    slUART_WriteString("RF_CH: ");
    slUART_WriteBufferBin(reg, 1);
    slNRF24_GetRegister(RF_SETUP, reg, 1);
    slUART_WriteString("RF_SETUP: ");
    slUART_WriteBufferBin(reg, 1);
    slNRF24_GetRegister(RX_PW_P0, reg, 1);
    slUART_WriteString("RX_PW_P0: ");
    slUART_WriteBufferBin(reg, 1);
    slNRF24_GetRegister(RX_PW_P1, reg, 1);
    slUART_WriteString("RX_PW_P1: ");
    slUART_WriteBufferBin(reg, 1);
    slNRF24_GetRegister(RX_ADDR_P1, reg, 5);
    slUART_WriteString("RX_ADDR_P1: ");
    slUART_WriteBufferBin(reg, 5);
    slNRF24_GetRegister(RX_ADDR_P0, reg, 5);
    slUART_WriteString("RX_ADDR_P0: ");
    slUART_WriteBufferBin(reg, 5);
    slNRF24_GetRegister(TX_ADDR, reg, 5);
    slUART_WriteString("TX_ADDR: ");
    slUART_WriteBufferBin(reg, 5);
}
#endif