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
LIBS:nRF24L01
LIBS:server-cache
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
L GND #PWR01
U 1 1 5A4F6F1D
P 1650 4750
F 0 "#PWR01" H 1650 4500 50  0001 C CNN
F 1 "GND" H 1650 4600 50  0000 C CNN
F 2 "" H 1650 4750 50  0000 C CNN
F 3 "" H 1650 4750 50  0000 C CNN
	1    1650 4750
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 5A4F6F46
P 9300 4250
F 0 "Y1" H 9300 4400 50  0000 C CNN
F 1 "8Mhz" H 9300 4100 50  0000 C CNN
F 2 "Crystals:Crystal_HC49-U_Vertical" H 9300 4250 50  0001 C CNN
F 3 "" H 9300 4250 50  0000 C CNN
	1    9300 4250
	-1   0    0    1   
$EndComp
$Comp
L C_Small C3
U 1 1 5A4F6F9F
P 9550 4550
F 0 "C3" H 9560 4620 50  0000 L CNN
F 1 "22p" H 9560 4470 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3_P2.5" H 9550 4550 50  0001 C CNN
F 3 "" H 9550 4550 50  0000 C CNN
	1    9550 4550
	-1   0    0    1   
$EndComp
$Comp
L C_Small C1
U 1 1 5A4F6FEC
P 9000 4550
F 0 "C1" H 9010 4620 50  0000 L CNN
F 1 "22p" H 9010 4470 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3_P2.5" H 9000 4550 50  0001 C CNN
F 3 "" H 9000 4550 50  0000 C CNN
	1    9000 4550
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
P 9450 1450
F 0 "R7" V 9530 1450 50  0000 C CNN
F 1 "10k" V 9450 1450 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 9380 1450 50  0001 C CNN
F 3 "" H 9450 1450 50  0000 C CNN
	1    9450 1450
	0    1    1    0   
$EndComp
$Comp
L +3.3V #PWR03
U 1 1 5A4F7308
P 4750 6350
F 0 "#PWR03" H 4750 6200 50  0001 C CNN
F 1 "+3.3V" H 4750 6490 50  0000 C CNN
F 2 "" H 4750 6350 50  0000 C CNN
F 3 "" H 4750 6350 50  0000 C CNN
	1    4750 6350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5A4F7326
P 4750 7200
F 0 "#PWR04" H 4750 6950 50  0001 C CNN
F 1 "GND" H 4750 7050 50  0000 C CNN
F 2 "" H 4750 7200 50  0000 C CNN
F 3 "" H 4750 7200 50  0000 C CNN
	1    4750 7200
	1    0    0    -1  
$EndComp
$Comp
L C_Small C2
U 1 1 5A4F7363
P 2000 2550
F 0 "C2" V 2050 2350 50  0000 L CNN
F 1 "100n" V 1950 2300 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D6_P5" H 2000 2550 50  0001 C CNN
F 3 "" H 2000 2550 50  0000 C CNN
	1    2000 2550
	0    1    1    0   
$EndComp
$Comp
L C_Small C4
U 1 1 5A4F744F
P 5150 6800
F 0 "C4" H 5160 6870 50  0000 L CNN
F 1 "100n" H 5160 6720 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D6_P5" H 5150 6800 50  0001 C CNN
F 3 "" H 5150 6800 50  0000 C CNN
	1    5150 6800
	1    0    0    -1  
$EndComp
$Comp
L CP C6
U 1 1 5A4F749C
P 6000 6800
F 0 "C6" H 6025 6900 50  0000 L CNN
F 1 "10u" H 6025 6700 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2" H 6038 6650 50  0001 C CNN
F 3 "" H 6000 6800 50  0000 C CNN
	1    6000 6800
	1    0    0    -1  
$EndComp
$Comp
L CP C7
U 1 1 5A4F74CD
P 6350 6800
F 0 "C7" H 6375 6900 50  0000 L CNN
F 1 "10u" H 6375 6700 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2" H 6388 6650 50  0001 C CNN
F 3 "" H 6350 6800 50  0000 C CNN
	1    6350 6800
	1    0    0    -1  
$EndComp
$Comp
L C_Small C5
U 1 1 5A4F753A
P 5550 6800
F 0 "C5" H 5560 6870 50  0000 L CNN
F 1 "100n" H 5560 6720 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D6_P5" H 5550 6800 50  0001 C CNN
F 3 "" H 5550 6800 50  0000 C CNN
	1    5550 6800
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X04 P1
U 1 1 5A4F78C1
P 9100 3250
F 0 "P1" H 9100 3500 50  0000 C CNN
F 1 "nRF24L01" H 9100 3000 50  0000 C CNN
F 2 "nrf24-connector:Socket_Strip_Straight_2x04_Pitch2.54mm" H 9100 2050 50  0001 C CNN
F 3 "" H 9100 2050 50  0000 C CNN
	1    9100 3250
	1    0    0    -1  
$EndComp
$Comp
L BC548 Q1
U 1 1 5A4F79A7
P 9050 1800
F 0 "Q1" H 9250 1875 50  0000 L CNN
F 1 "BC548" H 9250 1800 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 9250 1725 50  0000 L CIN
F 3 "" H 9050 1800 50  0000 L CNN
	1    9050 1800
	1    0    0    -1  
$EndComp
Text GLabel 4350 3400 2    60   Input ~ 0
RESET
Text GLabel 8750 1450 0    60   Input ~ 0
RESET
Text GLabel 4350 4250 2    60   Input ~ 0
PD7
Text GLabel 8650 1800 0    60   Input ~ 0
PD7
$Comp
L GND #PWR05
U 1 1 5A4F80A7
P 9800 2200
F 0 "#PWR05" H 9800 1950 50  0001 C CNN
F 1 "GND" H 9800 2050 50  0000 C CNN
F 2 "" H 9800 2200 50  0000 C CNN
F 3 "" H 9800 2200 50  0000 C CNN
	1    9800 2200
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR06
U 1 1 5A4F80D5
P 9800 1200
F 0 "#PWR06" H 9800 1050 50  0001 C CNN
F 1 "+3.3V" H 9800 1340 50  0000 C CNN
F 2 "" H 9800 1200 50  0000 C CNN
F 3 "" H 9800 1200 50  0000 C CNN
	1    9800 1200
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
Text GLabel 4350 3850 2    60   Input ~ 0
INT1
Text GLabel 9550 3400 2    60   Input ~ 0
INT1
Text GLabel 9550 3300 2    60   Input ~ 0
MOSI
Text GLabel 8700 3300 0    60   Input ~ 0
SCK
Text GLabel 8700 3400 0    60   Input ~ 0
MISO
$Comp
L GND #PWR07
U 1 1 5A4F93BD
P 8650 3100
F 0 "#PWR07" H 8650 2850 50  0001 C CNN
F 1 "GND" V 8550 3050 50  0000 C CNN
F 2 "" H 8650 3100 50  0000 C CNN
F 3 "" H 8650 3100 50  0000 C CNN
	1    8650 3100
	0    1    1    0   
$EndComp
$Comp
L +3.3V #PWR08
U 1 1 5A4F93EF
P 9550 3100
F 0 "#PWR08" H 9550 2950 50  0001 C CNN
F 1 "+3.3V" V 9450 3100 50  0000 C CNN
F 2 "" H 9550 3100 50  0000 C CNN
F 3 "" H 9550 3100 50  0000 C CNN
	1    9550 3100
	0    1    1    0   
$EndComp
$Comp
L CP C8
U 1 1 5A4F9535
P 9100 2800
F 0 "C8" H 9125 2900 50  0000 L CNN
F 1 "470u" H 9125 2700 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D8_L13_P3.8" H 9138 2650 50  0001 C CNN
F 3 "" H 9100 2800 50  0000 C CNN
	1    9100 2800
	0    1    1    0   
$EndComp
Text GLabel 4350 2050 2    60   Input ~ 0
CE
Text GLabel 9550 3200 2    60   Input ~ 0
CSN
Text GLabel 8700 3200 0    60   Input ~ 0
CE
NoConn ~ 4200 1950
$Comp
L LM2931AZ-3.3/5.0 U1
U 1 1 5A4FEC87
P 3200 6550
F 0 "U1" H 3200 6800 50  0000 C CNN
F 1 "HT7333" H 3200 6750 50  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 3200 6650 50  0000 C CIN
F 3 "" H 3200 6550 50  0000 C CNN
	1    3200 6550
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR09
U 1 1 5A4FED52
P 3900 6500
F 0 "#PWR09" H 3900 6350 50  0001 C CNN
F 1 "+3.3V" H 3900 6640 50  0000 C CNN
F 2 "" H 3900 6500 50  0000 C CNN
F 3 "" H 3900 6500 50  0000 C CNN
	1    3900 6500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 5A4FED90
P 3200 7050
F 0 "#PWR010" H 3200 6800 50  0001 C CNN
F 1 "GND" H 3200 6900 50  0000 C CNN
F 2 "" H 3200 7050 50  0000 C CNN
F 3 "" H 3200 7050 50  0000 C CNN
	1    3200 7050
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG011
U 1 1 5A4FFD97
P 2550 6400
F 0 "#FLG011" H 2550 6495 50  0001 C CNN
F 1 "PWR_FLAG" H 2550 6580 50  0000 C CNN
F 2 "" H 2550 6400 50  0000 C CNN
F 3 "" H 2550 6400 50  0000 C CNN
	1    2550 6400
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P3
U 1 1 5A50002A
P 2300 6850
F 0 "P3" H 2300 7000 50  0000 C CNN
F 1 "CONN_01X02" V 2400 6850 50  0000 C CNN
F 2 "Connect:GTK2400-V2" H 2300 6850 50  0001 C CNN
F 3 "" H 2300 6850 50  0000 C CNN
	1    2300 6850
	-1   0    0    1   
$EndComp
$Comp
L ATMEGA328P-P IC1
U 1 1 5A50FCD4
P 3200 3050
F 0 "IC1" H 2450 4300 50  0000 L BNN
F 1 "ATMEGA328P-P" H 3600 1650 50  0000 L BNN
F 2 "Housings_DIP:DIP-28_W7.62mm" H 3200 3050 50  0000 C CIN
F 3 "" H 3200 3050 50  0000 C CNN
	1    3200 3050
	1    0    0    -1  
$EndComp
Text GLabel 4350 2550 2    60   Input ~ 0
XTAL1
Text GLabel 4350 2650 2    60   Input ~ 0
XTAL2
Text GLabel 8750 3900 0    60   Input ~ 0
XTAL1
Text GLabel 8750 4100 0    60   Input ~ 0
XTAL2
$Comp
L GND #PWR012
U 1 1 5A51129F
P 9300 4900
F 0 "#PWR012" H 9300 4650 50  0001 C CNN
F 1 "GND" H 9300 4750 50  0000 C CNN
F 2 "" H 9300 4900 50  0000 C CNN
F 3 "" H 9300 4900 50  0000 C CNN
	1    9300 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 1300 1650 2250
Wire Wire Line
	6350 6550 6350 6650
Wire Wire Line
	6000 6550 6000 6650
Connection ~ 6000 6550
Wire Wire Line
	5550 6550 5550 6700
Connection ~ 5550 6550
Wire Wire Line
	5150 6700 5150 6550
Connection ~ 5150 6550
Wire Wire Line
	6350 7050 6350 6950
Wire Wire Line
	6000 7050 6000 6950
Connection ~ 6000 7050
Wire Wire Line
	5550 7050 5550 6900
Connection ~ 5550 7050
Wire Wire Line
	5150 6900 5150 7050
Connection ~ 5150 7050
Wire Wire Line
	1650 2250 2300 2250
Wire Wire Line
	1650 1950 2300 1950
Wire Wire Line
	8750 1450 9300 1450
Wire Wire Line
	9150 1450 9150 1600
Connection ~ 9150 1450
Wire Wire Line
	8850 1800 8650 1800
Wire Wire Line
	9150 2000 9150 2200
Wire Wire Line
	9150 2200 9800 2200
Wire Wire Line
	9600 1450 9800 1450
Wire Wire Line
	9800 1450 9800 1200
Wire Wire Line
	4200 2450 4350 2450
Wire Wire Line
	4200 2350 4350 2350
Wire Wire Line
	4200 2250 4350 2250
Wire Wire Line
	4200 2150 4350 2150
Wire Wire Line
	8700 3400 8850 3400
Wire Wire Line
	8700 3300 8850 3300
Wire Wire Line
	9350 3300 9550 3300
Wire Wire Line
	9350 3400 9550 3400
Wire Wire Line
	9350 3100 9550 3100
Wire Wire Line
	8650 3100 8850 3100
Wire Wire Line
	8950 2800 8750 2800
Wire Wire Line
	8750 2800 8750 3100
Connection ~ 8750 3100
Wire Wire Line
	9250 2800 9450 2800
Wire Wire Line
	9450 2800 9450 3100
Connection ~ 9450 3100
Wire Wire Line
	4350 2050 4200 2050
Wire Wire Line
	8700 3200 8850 3200
Wire Wire Line
	9350 3200 9550 3200
Wire Wire Line
	1900 2550 1650 2550
Wire Wire Line
	3600 6500 3900 6500
Wire Wire Line
	3200 6800 3200 7050
Wire Wire Line
	4750 6550 6350 6550
Wire Wire Line
	4750 7050 6350 7050
Wire Wire Line
	2550 6400 2550 6800
Wire Wire Line
	2550 6500 2800 6500
Wire Wire Line
	2550 6800 2500 6800
Connection ~ 2550 6500
Wire Wire Line
	2500 6900 3200 6900
Connection ~ 3200 6900
Wire Wire Line
	4750 7050 4750 7200
Wire Wire Line
	4750 6550 4750 6350
Wire Wire Line
	4350 3850 4200 3850
Wire Wire Line
	4350 4250 4200 4250
Wire Wire Line
	4350 2650 4200 2650
Wire Wire Line
	4200 2550 4350 2550
Wire Wire Line
	8750 4100 9000 4100
Wire Wire Line
	9000 4100 9000 4450
Wire Wire Line
	8750 3900 9550 3900
Wire Wire Line
	9550 3900 9550 4450
Wire Wire Line
	9150 4250 9000 4250
Connection ~ 9000 4250
Wire Wire Line
	9450 4250 9550 4250
Connection ~ 9550 4250
Wire Wire Line
	9000 4650 9000 4750
Wire Wire Line
	9000 4750 9550 4750
Wire Wire Line
	9550 4750 9550 4650
Wire Wire Line
	9300 4750 9300 4900
Connection ~ 9300 4750
Connection ~ 1650 1950
Wire Wire Line
	2100 2550 2300 2550
Wire Wire Line
	1650 2550 1650 4750
Connection ~ 1650 4150
Wire Wire Line
	2300 4250 1650 4250
Connection ~ 1650 4250
NoConn ~ 4200 2800
NoConn ~ 4200 2900
NoConn ~ 4200 3000
NoConn ~ 4200 3100
NoConn ~ 4200 3200
NoConn ~ 4200 3550
NoConn ~ 4200 3650
NoConn ~ 4200 3950
NoConn ~ 4200 4050
NoConn ~ 4200 4150
NoConn ~ 4200 3750
NoConn ~ 4200 3300
Wire Wire Line
	4350 3400 4200 3400
$Comp
L GNDPWR #PWR013
U 1 1 5A5127D3
P 1550 7200
F 0 "#PWR013" H 1550 7000 50  0001 C CNN
F 1 "GNDPWR" H 1550 7070 50  0000 C CNN
F 2 "" H 1550 7150 50  0000 C CNN
F 3 "" H 1550 7150 50  0000 C CNN
	1    1550 7200
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR014
U 1 1 5A512814
P 1550 6800
F 0 "#PWR014" H 1550 6650 50  0001 C CNN
F 1 "+3.3V" H 1550 6940 50  0000 C CNN
F 2 "" H 1550 6800 50  0000 C CNN
F 3 "" H 1550 6800 50  0000 C CNN
	1    1550 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 6800 1550 7200
Wire Wire Line
	2300 4150 1650 4150
$EndSCHEMATC