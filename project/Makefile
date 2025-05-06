all: libLcd.a main.elf
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS 	= -L/opt/ti/msp430_gcc/include -L../lib
#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

libLcd.a: font-5x7.o font-8x12.o font-11x16.o lcdutils.o lcddraw.o
	$(AR) crs $@ $^

clocksTimer.o: clocksTimer.c libTimer.h
font-5x7.o: font-5x7.c lcdutils.h
font-8x12.o: font-8x12.c lcdutils.h
font-11x16.o: font-11x16.c lcdutils.h
game.o: game.c game.h lcdutils.h lcdtypes.h clocksTimer.h
lcddraw.o: lcddraw.c lcddraw.h lcdutils.h lcdtypes.h
lcdutils.o: lcdutils.c lcdutils.h
main.o: main.c lcdutils.h lcddraw.h game.h clocksTimer.h
sr.o: sr.s
buzzer.o: buzzer.c buzzer.h

clean:
	rm -f libLcd.a *.o *.elf

main.elf: main.o game.o libLcd.a clocksTimer.o sr.o buzzer.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

load: main.elf
	msp430loader.sh $^

