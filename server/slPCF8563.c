//
// Created by dariusz on 19.02.18.
//

#include <avr/io.h>
#include "slI2C.h"
#include "slPCF8563.h"


void slPCF8563_Init(){
  
}


void slPCF8563_SetData(uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec){
  slI2C_Start();
  slI2C_WriteByte(slPCF8563_WRITE_ADDR);
  slI2C_WriteByte(slPCF8563_YEARS);
  slI2C_WriteByte(slPCF8563_ConvertToBCD(year));
  slI2C_Stop();

  slI2C_Start();
  slI2C_WriteByte(slPCF8563_WRITE_ADDR);
  slI2C_WriteByte(slPCF8563_CENTURY_MONTHS);
  slI2C_WriteByte(slPCF8563_ConvertToBCD(month));
  slI2C_Stop();

  slI2C_Start();
  slI2C_WriteByte(slPCF8563_WRITE_ADDR);
  slI2C_WriteByte(slPCF8563_DAYS);
  slI2C_WriteByte(slPCF8563_ConvertToBCD(day));
  slI2C_Stop();

  slI2C_Start();
  slI2C_WriteByte(slPCF8563_WRITE_ADDR);
  slI2C_WriteByte(slPCF8563_HOURS);
  slI2C_WriteByte(slPCF8563_ConvertToBCD(hour));
  slI2C_Stop();
  
  slI2C_Start();
  slI2C_WriteByte(slPCF8563_WRITE_ADDR);
  slI2C_WriteByte(slPCF8563_MINUTES);
  slI2C_WriteByte(slPCF8563_ConvertToBCD(min));
  slI2C_Stop();

  slI2C_Start();
  slI2C_WriteByte(slPCF8563_WRITE_ADDR);
  slI2C_WriteByte(slPCF8563_VL_SECONDS);
  slI2C_WriteByte(slPCF8563_ConvertToBCD(sec));
  slI2C_Stop();
}

void slPCF8563_GetData(uint8_t *year, uint8_t *month, uint8_t *day, uint8_t *hour, uint8_t *min, uint8_t *sec){
  slI2C_Start();
  slI2C_WriteByte(slPCF8563_READ_ADDR);
  slI2C_WriteByte(slPCF8563_YEARS);
  *year = slPCF8563_ConvertFromBCD(slI2C_ReadByte_NACK());
  slI2C_Stop();

  slI2C_Start();
  slI2C_WriteByte(slPCF8563_READ_ADDR);
  slI2C_WriteByte(slPCF8563_CENTURY_MONTHS);
  *month = slPCF8563_ConvertFromBCD(slI2C_ReadByte_NACK());
  slI2C_Stop();

  slI2C_Start();
  slI2C_WriteByte(slPCF8563_READ_ADDR);
  slI2C_WriteByte(slPCF8563_DAYS);
  *day = slPCF8563_ConvertFromBCD(slI2C_ReadByte_NACK());
  slI2C_Stop();

  slI2C_Start();
  slI2C_WriteByte(slPCF8563_READ_ADDR);
  slI2C_WriteByte(slPCF8563_HOURS);
  *hour = slPCF8563_ConvertFromBCD(slI2C_ReadByte_NACK());
  slI2C_Stop();
  
  slI2C_Start();
  slI2C_WriteByte(slPCF8563_READ_ADDR);
  slI2C_WriteByte(slPCF8563_MINUTES);
  *min = slPCF8563_ConvertFromBCD(slI2C_ReadByte_NACK());
  slI2C_Stop();

  slI2C_Start();
  slI2C_WriteByte(slPCF8563_READ_ADDR);
  slI2C_WriteByte(slPCF8563_VL_SECONDS);
  *sec = slPCF8563_ConvertFromBCD(slI2C_ReadByte_NACK());
  slI2C_Stop();
}