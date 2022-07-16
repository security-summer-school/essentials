CC = gcc
CFLAGS = -fPIC
TARGET = dynamic-linked

all: $(TARGET)

$(TARGET): libhello.so main.o
	$(CC) main.o -L. -lhello -o $@
	
libhello.so: hello.o
	$(CC) -shared $^ -o $@

hello.o: hello.c

main.o: main.c

clean:
	rm $(TARGET) *.o *.so

.PHONY: all clean
