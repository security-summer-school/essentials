include ../../assets/common.mk
CFLAGS = -fPIC

all: puts.so main 

main: main.c
	$(CC) $^ -o $@
	
puts.so: puts.o
	$(CC) -shared -fPIC $^ -o $@

clean:
	rm main *.o *.so

.PHONY: all clean
