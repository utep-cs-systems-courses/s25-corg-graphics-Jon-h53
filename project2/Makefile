all: libLcd.a dino.elf
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS 	= -L/opt/ti/msp430_gcc/include -L../lib
#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

libLcd.a: font-5x7.o lcdutils.o lcddraw.o
	$(AR) crs $@ $^
SRCS = buzzer.c clocksTimer.c font-5x7.c game.c graphics.c input.c lcddraw.c lcdutils.c led.c main.c sr.s wdt_handler.s
OBJS = $(SRCS:.c=.o)

clean:
	rm -f libLcd.a *.o *.elf
dino.elf: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
%.o: %.s
	msp430-elf-as -mmcu=msp430g2553 -o $@ $<

load: dino.elf
	msp430loader.sh $^
