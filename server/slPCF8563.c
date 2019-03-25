//
// Created by dariusz on 19.02.18.
//

#include <avr/io.h>
#include "slI2C.h"
#include "slPCF8563.h"
#include "slUart.h"

void slPCF8563_ResetDateTime(slPCF8563_DateTime *dateTime) {
  dateTime->year = 0;
  dateTime->month = 0;
  dateTime->day = 0;
  dateTime->weekday = 0;
  dateTime->hour = 0;
  dateTime->min = 0;
  dateTime->sec = 0;
}

uint8_t slPCF8563_ReadData(uint8_t register_addr, uint8_t *data, uint8_t length) {
  uint8_t index = 0;
  if (!slI2C_Start()) {
    //return 1;
  }
  if (!slI2C_WriteByte(slPCF8563_WRITE_ADDR)) {
    //return 1;
  }
  if (!slI2C_WriteByte(register_addr)) {
    //return 1;
  }
  slI2C_Stop();
  if (!slI2C_Start()) {
    //return 1;
  }
  if (!slI2C_WriteByte(slPCF8563_READ_ADDR)) {
    //return 1;
  }

  while (length--) {
    (length ? slI2C_ReadByte_ACK() : slI2C_ReadByte_NACK());
    data[index] = slI2C_returnReadValue();
    index++;
  }
  slI2C_Stop();
  return 0;
}

void slPCF8563_Init(uint8_t mode) {
  uint8_t tmp = 0x0;
  slI2C_Start();
  slI2C_WriteByte(slPCF8563_WRITE_ADDR);
  slI2C_WriteByte(slPCF8563_CONTROL_STATUS_1);
  slI2C_WriteByte(tmp);
  slI2C_Stop();

  mode &= 0x13;//0b00010011           //Mask unnecessary bits
  slI2C_Start();
  slI2C_WriteByte(slPCF8563_WRITE_ADDR);
  slI2C_WriteByte(slPCF8563_CONTROL_STATUS_2);
  slI2C_WriteByte(mode);
  slI2C_Stop();
}

uint8_t slPCF8563_SetData(slPCF8563_DateTime *dateTime) {
  uint8_t century = 0;

  if (dateTime->sec >= 60 || dateTime->min >= 60 || dateTime->hour >= 24 || dateTime->day >= 32 ||
      dateTime->weekday > 6 || dateTime->month > 12 || dateTime->year < 1900 || dateTime->year >= 2100) {
    return 1;
  }

  if (dateTime->year >= 2000) {
    century = 1 << 7;
    dateTime->year = dateTime->year - 2000;
  } else {
    dateTime->year = dateTime->year - 1900;
  }

  slI2C_Start();
  slI2C_WriteByte(slPCF8563_WRITE_ADDR);
  slI2C_WriteByte(slPCF8563_VL_SECONDS);
  slI2C_WriteByte(slPCF8563_ConvertToBCD(dateTime->sec) & 0x7F);
  slI2C_Stop();
  slI2C_Start();
  slI2C_WriteByte(slPCF8563_WRITE_ADDR);
  slI2C_WriteByte(slPCF8563_MINUTES);
  slI2C_WriteByte(slPCF8563_ConvertToBCD(dateTime->min) & 0x7F);
  slI2C_Stop();
  slI2C_Start();
  slI2C_WriteByte(slPCF8563_WRITE_ADDR);
  slI2C_WriteByte(slPCF8563_HOURS);
  slI2C_WriteByte(slPCF8563_ConvertToBCD(dateTime->hour) & 0x3F);
  slI2C_Stop();

  slI2C_Start();
  slI2C_WriteByte(slPCF8563_WRITE_ADDR);
  slI2C_WriteByte(slPCF8563_DAYS);
  slI2C_WriteByte(slPCF8563_ConvertToBCD(dateTime->day) & 0x3F);
  slI2C_Stop();

  slI2C_Start();
  slI2C_WriteByte(slPCF8563_WRITE_ADDR);
  slI2C_WriteByte(slPCF8563_WEEKDAYS);
  slI2C_WriteByte(slPCF8563_ConvertToBCD(dateTime->weekday) & 0x07);
  slI2C_Stop();

  slI2C_Start();
  slI2C_WriteByte(slPCF8563_WRITE_ADDR);
  slI2C_WriteByte(slPCF8563_CENTURY_MONTHS);
  slI2C_WriteByte((slPCF8563_ConvertToBCD(dateTime->month) | century) & 0x1F);
  slI2C_Stop();

  slI2C_Start();
  slI2C_WriteByte(slPCF8563_WRITE_ADDR);
  slI2C_WriteByte(slPCF8563_YEARS);
  slI2C_WriteByte(slPCF8563_ConvertToBCD(dateTime->year));
  slI2C_Stop();

  return 0;
}

void slPCF8563_GetData(slPCF8563_DateTime *dateTime) {
  uint8_t data[8];
  if (slPCF8563_ReadData(slPCF8563_VL_SECONDS, data, 7)) {
    slUART_WriteStringNl("Error getting data from slPCF8563");
  }

  dateTime->sec = (((data[0] >> 4) & 0x07) * 10) + (data[0] & 0x0F);
  dateTime->min = (((data[1] >> 4) & 0x07) * 10) + (data[1] & 0x0F);
  dateTime->hour = (((data[2] >> 4) & 0x03) * 10) + (data[2] & 0x0F);
  dateTime->day = (((data[3] >> 4) & 0x03) * 10) + (data[3] & 0x0F);
  dateTime->weekday = (data[4] & 0x07);
  dateTime->month = ((data[5] >> 4) & 0x01) * 10 + (data[5] & 0x0F);
  dateTime->year = 2000 + ((data[6] >> 4) & 0x0F) * 10 + (data[6] & 0x0F);

  if (data[5] & 0x80) {
    dateTime->year += 100;
  }

  if (data[0] & 0x80) //Clock integrity not guaranted
  {
    //return 1;
  }
}