CFLAGS = -m32 -Wall -fno-PIC -g -O0
LDFLAGS = -m32 -no-pie

.PHONY: all clean

all: main

main: main.o

main.o: main.c

clean:
	-rm -f main.o
	-rm -f main
	-rm -f *~
