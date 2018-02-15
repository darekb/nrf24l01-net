MCU=atmega328
F_CPU=16000000
TARGET=main
CC=avr-gcc
CFLAGS=-I/home/dariusz/Downloads/simavr-master/simavr/sim/avr
CFLAGS+=-I/home/dariusz/Downloads/simavr-master/simavr/sim
CFLAGS+=-mmcu=$(MCU)
#CFLAGS+=-fpack-struct
#CFLAGS+=-fshort-enums
CFLAGS+=-Wall
CFLAGS+=-gdwarf-2
CFLAGS+=-Werror
#CFLAGS+=-pedantic
#CFLAGS+=-pedantic-errors
#CFLAGS+=-funsigned-char
#CFLAGS+=-funsigned-bitfields
#CFLAGS+=-ffunction-sections
#CFLAGS+=-c
CFLAGS+=-O1
CFLAGS+=-std=gnu99

all: clean $(TARGET).o slUart.o
	$(CC) $(CFLAGS) -Wl,--undefined=_mmcu,--section-start=.mmcu=0x910000 $(TARGET).o slUart.o -o $(TARGET).elf
	avr-objcopy -j .text -j .data -O ihex $(TARGET).elf $(TARGET).hex

sim:
	~/Downloads/simavr-master/simavr/run_avr -mcu $(MCU) -freq $(F_CPU) $(TARGET).elf

$(TARGET).o:
	$(CC) $(CFLAGS) -c $(TARGET).c -o $(TARGET).o

clean:
	rm -f *.o *.hex *.elf gtkwave_trace.vcd

slUart.o:
	$(CC) $(CFLAGS) -c slUart.c -o slUart.o