include ../../../assets/common.mk
TARGET = static-linked

all: $(TARGET)

$(TARGET): libhello.a main.o
	$(CC) -static main.o -L. -lhello -o $@
	
libhello.a: hello.o
	ar rcs $@ $^

hello.o: hello.c

main.o: main.c

clean:
	rm $(TARGET) *.o *.a

.PHONY: all clean
