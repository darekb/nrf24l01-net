EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ATMEGA8-P IC1
U 1 1 5A4F6E80
P 3200 3050
F 0 "IC1" H 2450 4350 50  0000 L BNN
F 1 "ATMEGA8-P" H 3700 1600 50  0000 L BNN
F 2 "Housings_DIP:DIP-28_W7.62mm" H 3200 3050 50  0000 C CIN
F 3 "" H 3200 3050 50  0000 C CNN
	1    3200 3050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 5A4F6F1D
P 2250 5000
F 0 "#PWR01" H 2250 4750 50  0001 C CNN
F 1 "GND" H 2250 4850 50  0000 C CNN
F 2 "" H 2250 5000 50  0000 C CNN
F 3 "" H 2250 5000 50  0000 C CNN
	1    2250 5000
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 5A4F6F46
P 2050 3000
F 0 "Y1" H 2050 3150 50  0000 C CNN
F 1 "8Mhz" H 2050 2850 50  0000 C CNN
F 2 "Crystals:Crystal_HC49-U_Vertical" H 2050 3000 50  0001 C CNN
F 3 "" H 2050 3000 50  0000 C CNN
	1    2050 3000
	-1   0    0    1   
$EndComp
$Comp
L C_Small C3
U 1 1 5A4F6F9F
P 2250 3350
F 0 "C3" H 2260 3420 50  0000 L CNN
F 1 "22n" H 2260 3270 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3_P2.5" H 2250 3350 50  0001 C CNN
F 3 "" H 2250 3350 50  0000 C CNN
	1    2250 3350
	-1   0    0    1   
$EndComp
$Comp
L C_Small C1
U 1 1 5A4F6FEC
P 1850 3350
F 0 "C1" H 1860 3420 50  0000 L CNN
F 1 "22n" H 1860 3270 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3_P2.5" H 1850 3350 50  0001 C CNN
F 3 "" H 1850 3350 50  0000 C CNN
	1    1850 3350
	-1   0    0    1   
$EndComp
$Comp
L +3.3V #PWR02
U 1 1 5A4F7277
P 1650 1300
F 0 "#PWR02" H 1650 1150 50  0001 C CNN
F 1 "+3.3V" H 1650 1440 50  0000 C CNN
F 2 "" H 1650 1300 50  0000 C CNN
F 3 "" H 1650 1300 50  0000 C CNN
	1    1650 1300
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 5A4F7297
P 7950 1450
F 0 "R7" V 8030 1450 50  0000 C CNN
F 1 "10k" V 7950 1450 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 7880 1450 50  0001 C CNN
F 3 "" H 7950 1450 50  0000 C CNN
	1    7950 1450
	0    1    1    0   
$EndComp
$Comp
L +3.3V #PWR03
U 1 1 5A4F7308
P 5850 5150
F 0 "#PWR03" H 5850 5000 50  0001 C CNN
F 1 "+3.3V" H 5850 5290 50  0000 C CNN
F 2 "" H 5850 5150 50  0000 C CNN
F 3 "" H 5850 5150 50  0000 C CNN
	1    5850 5150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5A4F7326
P 5850 6000
F 0 "#PWR04" H 5850 5750 50  0001 C CNN
F 1 "GND" H 5850 5850 50  0000 C CNN
F 2 "" H 5850 6000 50  0000 C CNN
F 3 "" H 5850 6000 50  0000 C CNN
	1    5850 6000
	1    0    0    -1  
$EndComp
$Comp
L C_Small C2
U 1 1 5A4F7363
P 2000 2250
F 0 "C2" V 2050 2050 50  0000 L CNN
F 1 "100n" V 1950 2000 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D6_P5" H 2000 2250 50  0001 C CNN
F 3 "" H 2000 2250 50  0000 C CNN
	1    2000 2250
	0    1    1    0   
$EndComp
$Comp
L C_Small C4
U 1 1 5A4F744F
P 6250 5600
F 0 "C4" H 6260 5670 50  0000 L CNN
F 1 "100n" H 6260 5520 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D6_P5" H 6250 5600 50  0001 C CNN
F 3 "" H 6250 5600 50  0000 C CNN
	1    6250 5600
	1    0    0    -1  
$EndComp
$Comp
L CP C6
U 1 1 5A4F749C
P 7100 5600
F 0 "C6" H 7125 5700 50  0000 L CNN
F 1 "10u" H 7125 5500 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D8_L13_P3.8" H 7138 5450 50  0001 C CNN
F 3 "" H 7100 5600 50  0000 C CNN
	1    7100 5600
	1    0    0    -1  
$EndComp
$Comp
L CP C7
U 1 1 5A4F74CD
P 7450 5600
F 0 "C7" H 7475 5700 50  0000 L CNN
F 1 "10u" H 7475 5500 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D8_L13_P3.8" H 7488 5450 50  0001 C CNN
F 3 "" H 7450 5600 50  0000 C CNN
	1    7450 5600
	1    0    0    -1  
$EndComp
$Comp
L C_Small C5
U 1 1 5A4F753A
P 6650 5600
F 0 "C5" H 6660 5670 50  0000 L CNN
F 1 "100n" H 6660 5520 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D6_P5" H 6650 5600 50  0001 C CNN
F 3 "" H 6650 5600 50  0000 C CNN
	1    6650 5600
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X04 P1
U 1 1 5A4F78C1
P 7600 3250
F 0 "P1" H 7600 3500 50  0000 C CNN
F 1 "nRF24L01" H 7600 3000 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_2x04" H 7600 2050 50  0001 C CNN
F 3 "" H 7600 2050 50  0000 C CNN
	1    7600 3250
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P2
U 1 1 5A4F7940
P 7950 4350
F 0 "P2" H 7950 4600 50  0000 C CNN
F 1 "BME280" V 8050 4350 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x04" H 7950 4350 50  0001 C CNN
F 3 "" H 7950 4350 50  0000 C CNN
	1    7950 4350
	1    0    0    -1  
$EndComp
$Comp
L BC548 Q1
U 1 1 5A4F79A7
P 7550 1800
F 0 "Q1" H 7750 1875 50  0000 L CNN
F 1 "BC548" H 7750 1800 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 7750 1725 50  0000 L CIN
F 3 "" H 7550 1800 50  0000 L CNN
	1    7550 1800
	1    0    0    -1  
$EndComp
Text GLabel 2250 1950 0    60   Input ~ 0
RESET
Text GLabel 7250 1450 0    60   Input ~ 0
RESET
Text GLabel 4350 4050 2    60   Input ~ 0
PD7
Text GLabel 7150 1800 0    60   Input ~ 0
PD7
$Comp
L GND #PWR05
U 1 1 5A4F80A7
P 8300 2200
F 0 "#PWR05" H 8300 1950 50  0001 C CNN
F 1 "GND" H 8300 2050 50  0000 C CNN
F 2 "" H 8300 2200 50  0000 C CNN
F 3 "" H 8300 2200 50  0000 C CNN
	1    8300 2200
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR06
U 1 1 5A4F80D5
P 8300 1200
F 0 "#PWR06" H 8300 1050 50  0001 C CNN
F 1 "+3.3V" H 8300 1340 50  0000 C CNN
F 2 "" H 8300 1200 50  0000 C CNN
F 3 "" H 8300 1200 50  0000 C CNN
	1    8300 1200
	1    0    0    -1  
$EndComp
Text GLabel 4350 2150 2    60   Input ~ 0
CSN
Text GLabel 4350 2250 2    60   Input ~ 0
MOSI
Text GLabel 4350 2350 2    60   Input ~ 0
MISO
Text GLabel 4350 2450 2    60   Input ~ 0
SCK
Text GLabel 4350 3650 2    60   Input ~ 0
INT1
Text GLabel 4350 3050 2    60   Input ~ 0
SDA
Text GLabel 4350 3150 2    60   Input ~ 0
SCL
Text GLabel 7150 4400 0    60   Input ~ 0
SCL
Text GLabel 7150 4500 0    60   Input ~ 0
SDA
$Comp
L +3.3V #PWR07
U 1 1 5A4F88CA
P 7000 3950
F 0 "#PWR07" H 7000 3800 50  0001 C CNN
F 1 "+3.3V" H 7000 4090 50  0000 C CNN
F 2 "" H 7000 3950 50  0000 C CNN
F 3 "" H 7000 3950 50  0000 C CNN
	1    7000 3950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 5A4F88F8
P 7650 4600
F 0 "#PWR08" H 7650 4350 50  0001 C CNN
F 1 "GND" H 7650 4450 50  0000 C CNN
F 2 "" H 7650 4600 50  0000 C CNN
F 3 "" H 7650 4600 50  0000 C CNN
	1    7650 4600
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 5A4F8C17
P 7500 4150
F 0 "R6" V 7580 4150 50  0000 C CNN
F 1 "4k7" V 7500 4150 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 7430 4150 50  0001 C CNN
F 3 "" H 7500 4150 50  0000 C CNN
	1    7500 4150
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 5A4F8C86
P 7300 4150
F 0 "R5" V 7380 4150 50  0000 C CNN
F 1 "4k7" V 7300 4150 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 7230 4150 50  0001 C CNN
F 3 "" H 7300 4150 50  0000 C CNN
	1    7300 4150
	1    0    0    -1  
$EndComp
Text GLabel 8050 3400 2    60   Input ~ 0
INT1
Text GLabel 8050 3300 2    60   Input ~ 0
MOSI
Text GLabel 7200 3300 0    60   Input ~ 0
SCK
Text GLabel 7200 3400 0    60   Input ~ 0
MISO
$Comp
L GND #PWR09
U 1 1 5A4F93BD
P 7150 3100
F 0 "#PWR09" H 7150 2850 50  0001 C CNN
F 1 "GND" V 7050 3050 50  0000 C CNN
F 2 "" H 7150 3100 50  0000 C CNN
F 3 "" H 7150 3100 50  0000 C CNN
	1    7150 3100
	0    1    1    0   
$EndComp
$Comp
L +3.3V #PWR010
U 1 1 5A4F93EF
P 8050 3100
F 0 "#PWR010" H 8050 2950 50  0001 C CNN
F 1 "+3.3V" V 7950 3100 50  0000 C CNN
F 2 "" H 8050 3100 50  0000 C CNN
F 3 "" H 8050 3100 50  0000 C CNN
	1    8050 3100
	0    1    1    0   
$EndComp
$Comp
L CP C8
U 1 1 5A4F9535
P 7600 2800
F 0 "C8" H 7625 2900 50  0000 L CNN
F 1 "470u" H 7625 2700 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D8_L13_P3.8" H 7638 2650 50  0001 C CNN
F 3 "" H 7600 2800 50  0000 C CNN
	1    7600 2800
	0    1    1    0   
$EndComp
Text GLabel 4350 2050 2    60   Input ~ 0
CE
Text GLabel 8050 3200 2    60   Input ~ 0
CSN
Text GLabel 7200 3200 0    60   Input ~ 0
CE
$Comp
L R R1
U 1 1 5A4FB155
P 5900 1750
F 0 "R1" V 5980 1750 50  0000 C CNN
F 1 "12k" V 5900 1750 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 5830 1750 50  0001 C CNN
F 3 "" H 5900 1750 50  0000 C CNN
	1    5900 1750
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 5A4FB1CA
P 5900 2150
F 0 "R2" V 5980 2150 50  0000 C CNN
F 1 "33k" V 5900 2150 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 5830 2150 50  0001 C CNN
F 3 "" H 5900 2150 50  0000 C CNN
	1    5900 2150
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR011
U 1 1 5A4FB3DF
P 5900 1500
F 0 "#PWR011" H 5900 1350 50  0001 C CNN
F 1 "+3.3V" H 5900 1640 50  0000 C CNN
F 2 "" H 5900 1500 50  0000 C CNN
F 3 "" H 5900 1500 50  0000 C CNN
	1    5900 1500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 5A4FB417
P 5900 2450
F 0 "#PWR012" H 5900 2200 50  0001 C CNN
F 1 "GND" H 5900 2300 50  0000 C CNN
F 2 "" H 5900 2450 50  0000 C CNN
F 3 "" H 5900 2450 50  0000 C CNN
	1    5900 2450
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 5A4FBC17
P 5950 3350
F 0 "R3" V 6030 3350 50  0000 C CNN
F 1 "12k" V 5950 3350 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 5880 3350 50  0001 C CNN
F 3 "" H 5950 3350 50  0000 C CNN
	1    5950 3350
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR013
U 1 1 5A4FBC24
P 5950 3100
F 0 "#PWR013" H 5950 2950 50  0001 C CNN
F 1 "+3.3V" H 5950 3240 50  0000 C CNN
F 2 "" H 5950 3100 50  0000 C CNN
F 3 "" H 5950 3100 50  0000 C CNN
	1    5950 3100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 5A4FBC2A
P 5950 4250
F 0 "#PWR014" H 5950 4000 50  0001 C CNN
F 1 "GND" H 5950 4100 50  0000 C CNN
F 2 "" H 5950 4250 50  0000 C CNN
F 3 "" H 5950 4250 50  0000 C CNN
	1    5950 4250
	1    0    0    -1  
$EndComp
$Comp
L Photores R4
U 1 1 5A4FBC88
P 5950 3950
F 0 "R4" V 6030 3950 50  0000 C CNN
F 1 "5k-10k" V 6160 3950 50  0000 C TNN
F 2 "Discret:R1" V 5880 3950 50  0001 C CNN
F 3 "" H 5950 3950 50  0000 C CNN
	1    5950 3950
	1    0    0    -1  
$EndComp
NoConn ~ 4200 1950
NoConn ~ 4200 2650
NoConn ~ 4200 2950
NoConn ~ 4200 3350
NoConn ~ 4200 3750
NoConn ~ 4200 3850
NoConn ~ 4200 3950
NoConn ~ 4200 3550
NoConn ~ 4200 3450
$Comp
L LM2931AZ-3.3/5.0 U1
U 1 1 5A4FEC87
P 3450 5750
F 0 "U1" H 3450 6000 50  0000 C CNN
F 1 "LM2931AZ-3.3/5.0" H 3450 5950 50  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 3450 5850 50  0000 C CIN
F 3 "" H 3450 5750 50  0000 C CNN
	1    3450 5750
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR015
U 1 1 5A4FED52
P 4150 5700
F 0 "#PWR015" H 4150 5550 50  0001 C CNN
F 1 "+3.3V" H 4150 5840 50  0000 C CNN
F 2 "" H 4150 5700 50  0000 C CNN
F 3 "" H 4150 5700 50  0000 C CNN
	1    4150 5700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 5A4FED90
P 3450 6250
F 0 "#PWR016" H 3450 6000 50  0001 C CNN
F 1 "GND" H 3450 6100 50  0000 C CNN
F 2 "" H 3450 6250 50  0000 C CNN
F 3 "" H 3450 6250 50  0000 C CNN
	1    3450 6250
	1    0    0    -1  
$EndComp
Text GLabel 4350 2850 2    60   Input ~ 0
PC2
Text GLabel 4350 2750 2    60   Input ~ 0
PC1
Text GLabel 5700 1950 0    60   Input ~ 0
PC1
Text GLabel 5750 3550 0    60   Input ~ 0
PC2
$Comp
L PWR_FLAG #FLG017
U 1 1 5A4FFD97
P 2800 5600
F 0 "#FLG017" H 2800 5695 50  0001 C CNN
F 1 "PWR_FLAG" H 2800 5780 50  0000 C CNN
F 2 "" H 2800 5600 50  0000 C CNN
F 3 "" H 2800 5600 50  0000 C CNN
	1    2800 5600
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P3
U 1 1 5A50002A
P 2550 6050
F 0 "P3" H 2550 6200 50  0000 C CNN
F 1 "CONN_01X02" V 2650 6050 50  0000 C CNN
F 2 "Connect:GTK2400-V2" H 2550 6050 50  0001 C CNN
F 3 "" H 2550 6050 50  0000 C CNN
	1    2550 6050
	-1   0    0    1   
$EndComp
Wire Wire Line
	2300 2650 1850 2650
Wire Wire Line
	1850 2650 1850 3000
Wire Wire Line
	1850 3000 1850 3250
Wire Wire Line
	1900 3000 1850 3000
Connection ~ 1850 3000
Wire Wire Line
	2300 2850 2250 2850
Wire Wire Line
	2250 2850 2250 3000
Wire Wire Line
	2250 3000 2250 3250
Wire Wire Line
	2200 3000 2250 3000
Connection ~ 2250 3000
Wire Wire Line
	1850 3450 1850 3600
Wire Wire Line
	1650 4750 2250 4750
Wire Wire Line
	2250 4750 3200 4750
Wire Wire Line
	3200 4750 3200 4550
Connection ~ 2250 4750
Wire Wire Line
	2300 2350 1650 2350
Wire Wire Line
	1650 2250 1650 2350
Wire Wire Line
	1650 2350 1650 3600
Wire Wire Line
	1650 3600 1650 4750
Wire Wire Line
	2250 4750 2250 5000
Wire Wire Line
	1650 3600 1850 3600
Wire Wire Line
	1850 3600 2250 3600
Connection ~ 1650 3600
Wire Wire Line
	2250 3600 2250 3450
Connection ~ 1850 3600
Connection ~ 1650 2350
Wire Wire Line
	1650 1300 1650 1500
Wire Wire Line
	1650 1500 1650 2150
Wire Wire Line
	7450 5350 7450 5450
Wire Wire Line
	7100 5450 7100 5350
Connection ~ 7100 5350
Wire Wire Line
	6650 5500 6650 5350
Connection ~ 6650 5350
Wire Wire Line
	6250 5500 6250 5350
Connection ~ 6250 5350
Wire Wire Line
	7450 5850 7450 5750
Wire Wire Line
	7100 5750 7100 5850
Connection ~ 7100 5850
Wire Wire Line
	6650 5700 6650 5850
Connection ~ 6650 5850
Wire Wire Line
	6250 5700 6250 5850
Connection ~ 6250 5850
Wire Wire Line
	1650 2150 2300 2150
Wire Wire Line
	3200 1650 3200 1500
Wire Wire Line
	3200 1500 1650 1500
Connection ~ 1650 1500
Wire Wire Line
	2300 1950 2250 1950
Wire Wire Line
	7250 1450 7650 1450
Wire Wire Line
	7650 1450 7800 1450
Wire Wire Line
	7650 1450 7650 1600
Connection ~ 7650 1450
Wire Wire Line
	4350 4050 4200 4050
Wire Wire Line
	7350 1800 7150 1800
Wire Wire Line
	7650 2000 7650 2200
Wire Wire Line
	7650 2200 8300 2200
Wire Wire Line
	8100 1450 8300 1450
Wire Wire Line
	8300 1450 8300 1200
Wire Wire Line
	4200 3650 4350 3650
Wire Wire Line
	4200 2450 4350 2450
Wire Wire Line
	4200 2350 4350 2350
Wire Wire Line
	4200 2250 4350 2250
Wire Wire Line
	4200 2150 4350 2150
Wire Wire Line
	4350 3150 4200 3150
Wire Wire Line
	4200 3050 4350 3050
Wire Wire Line
	7150 4500 7300 4500
Wire Wire Line
	7300 4500 7750 4500
Wire Wire Line
	7150 4400 7500 4400
Wire Wire Line
	7500 4400 7750 4400
Wire Wire Line
	7750 4300 7650 4300
Wire Wire Line
	7650 4300 7650 4600
Wire Wire Line
	7000 3950 7300 3950
Wire Wire Line
	7300 3950 7500 3950
Wire Wire Line
	7500 3950 7650 3950
Wire Wire Line
	7650 3950 7650 4200
Wire Wire Line
	7650 4200 7750 4200
Wire Wire Line
	7300 4300 7300 4500
Connection ~ 7300 4500
Wire Wire Line
	7500 4300 7500 4400
Connection ~ 7500 4400
Wire Wire Line
	7500 4000 7500 3950
Connection ~ 7500 3950
Wire Wire Line
	7300 4000 7300 3950
Connection ~ 7300 3950
Wire Wire Line
	7200 3400 7350 3400
Wire Wire Line
	7200 3300 7350 3300
Wire Wire Line
	7850 3300 8050 3300
Wire Wire Line
	7850 3400 8050 3400
Wire Wire Line
	7850 3100 7950 3100
Wire Wire Line
	7950 3100 8050 3100
Wire Wire Line
	7150 3100 7250 3100
Wire Wire Line
	7250 3100 7350 3100
Wire Wire Line
	7450 2800 7250 2800
Wire Wire Line
	7250 2800 7250 3100
Connection ~ 7250 3100
Wire Wire Line
	7750 2800 7950 2800
Wire Wire Line
	7950 2800 7950 3100
Connection ~ 7950 3100
Wire Wire Line
	4350 2050 4200 2050
Wire Wire Line
	7200 3200 7350 3200
Wire Wire Line
	7850 3200 8050 3200
Wire Wire Line
	5700 1950 5900 1950
Wire Wire Line
	5900 1900 5900 1950
Wire Wire Line
	5900 1950 5900 2000
Connection ~ 5900 1950
Wire Wire Line
	5900 1600 5900 1500
Wire Wire Line
	5900 2450 5900 2300
Wire Wire Line
	5750 3550 5950 3550
Connection ~ 5950 3550
Wire Wire Line
	5950 3200 5950 3100
Wire Wire Line
	5950 4050 5950 3900
Wire Wire Line
	5950 3500 5950 3550
Wire Wire Line
	5950 3550 5950 3700
Wire Wire Line
	5950 4200 5950 4250
Wire Wire Line
	1900 2250 1650 2250
Wire Wire Line
	2100 2250 2300 2250
Wire Wire Line
	3850 5700 4150 5700
Wire Wire Line
	3450 6000 3450 6100
Wire Wire Line
	3450 6100 3450 6250
Wire Wire Line
	4350 2750 4200 2750
Wire Wire Line
	4350 2850 4200 2850
Wire Wire Line
	7450 5350 7100 5350
Wire Wire Line
	7100 5350 6650 5350
Wire Wire Line
	6650 5350 6250 5350
Wire Wire Line
	6250 5350 5850 5350
Wire Wire Line
	7450 5850 7100 5850
Wire Wire Line
	7100 5850 6650 5850
Wire Wire Line
	6650 5850 6250 5850
Wire Wire Line
	6250 5850 5850 5850
Wire Wire Line
	2800 5600 2800 5700
Wire Wire Line
	2800 5700 2800 6000
Wire Wire Line
	2800 5700 3050 5700
Wire Wire Line
	2800 6000 2750 6000
Connection ~ 2800 5700
Wire Wire Line
	2750 6100 3450 6100
Connection ~ 3450 6100
Wire Wire Line
	5850 5850 5850 6000
Wire Wire Line
	5850 5350 5850 5150
$EndSCHEMATC
