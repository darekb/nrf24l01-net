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


//CONTROL_STATUS_1 bits

#define CONTROL_STATUS_1_TEST1      0x0<<7  
//Default value. must be set to logic 0 during normal operations

#define CONTROL_STATUS_1_STOP_ON    0x1<<5  
//all RTC divider chain flip-flops are asynchronously set to logic 0; the RTC clock is stopped (CLKOUT at 32.768 kHz is still available)
#define CONTROL_STATUS_1_STOP_OFF   0x0<<5  //Default value. 
//RTC source clock runs


#define CONTROL_STATUS_1_TESTC_ON   0x1<<3  //Default value. 
//Power-On Reset (POR) override may be enabled
#define CONTROL_STATUS_1_TESTC_OFF  0x0<<3  
//Power-On Reset (POR) override facility is disabled; set to logic 0 for normal operation


//CONTROL_STATUS_2 bits

#define CONTROL_STATUS_2_TI_TP_OFF  0x0<<4  //Default value. 
//INT is active when TF is active (subject to the status of TIE)
#define CONTROL_STATUS_2_TI_TP_ON   0x1<<4  
//INT pulses active according to Table 7 (subject to the status of TIE);


#define CONTROL_STATUS_2_AF_OFF     0x0<<3  //Default value. 
//read: alarm flag inactive
//write: alarm flag is cleared
#define CONTROL_STATUS_2_AF_ON      0x1<<3
//read: alarm flag active
//write: alarm flag remains unchanged

#define CONTROL_STATUS_2_TF_OFF     0x0<<2  //Default value. 
//read: timer flag inactive
//write: timer flag is cleared
#define CONTROL_STATUS_2_TF_ON      0x1<<2
//read: timer flag active
//write: timer flag remains unchanged


#define CONTROL_STATUS_2_AIE_OFF    0x0<<1  //Default value. 
//alarm interrupt disabled
#define CONTROL_STATUS_2_AIE_ON     0x1<<1
//alarm interrupt enabled


#define CONTROL_STATUS_2_TIE_OFF    0x0  //Default value. 
//timer interrupt disabled
#define CONTROL_STATUS_2_TIE_ON     0x1
//timer interrupt enabled

#endif //CMAKE_AVR_SLPCF8563_H
