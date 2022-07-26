OBJS = f1.o f2.o f3.o get_flag_part.o main.o
ASFLAGS = -f elf64

all: main

main: $(OBJS)
	gcc -o $@ $^ -no-pie

main.o: main.asm
	nasm $(ASFLAGS) $^ -o $@

clean:
	rm -f main

.PHONY: all clean
