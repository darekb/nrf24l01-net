//
// Created by dariusz on 19.02.18.
//

#ifndef CMAKE_AVR_SLPCF8563_H
#define CMAKE_AVR_SLPCF8563_H


//registers
#define CONTROL_STATUS_1 0x00
#define CONTROL_STATUS_2 0x01
#define VL_SECONDS       0x02  //SECONDS (0 to 59)        7bits
#define MINUTES          0x03  //MINUTES (0 to 59)        7bits
#define HOURS            0x04  //HOURS (0 to 23)          6bits
#define DAYS             0x05  //DAYS (1 to 31)           6bits
#define WEEKDAYS         0x06  //WEEKDAYS (0 to 6)        3bits
#define CENTURY_MONTHS   0x07  //MONTHS (1 to 12)         5bits
#define YEARS            0x08  //YEARS (0 to 99)          8bits
#define MINUTE_ALARM     0x09  //MINUTE_ALARM (0 to 59)   7bits
#define HOUR_ALARM       0x0A  //HOUR_ALARM (0 to 23)     6bits
#define DAY_ALARM        0x0B  //DAY_ALARM (1 to 31)      6bits
#define WEEKDAY_ALARM    0x0C  //WEEKDAY_ALARM (0 to 6)   3bits
#define CLKOUT_CONTROL   0x0D  //FD[1:0]                  2bits
#define TIMER_CONTROL    0x0E  //TD[1:0]                  2bits
#define TIMER            0x0F  //TIMER[7:0]               8bits




#endif //CMAKE_AVR_SLPCF8563_H
