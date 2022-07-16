CC = gcc

all: libhide_flag.so secretive

secretive: secretive.c
	$(CC) $^ -L. -lhide_flag -o $@
	
libhide_flag.so: hide_flag.c
	$(CC) -shared -fPIC $^ -o $@

clean:
	rm secretive *.o *.so

.PHONY: all clean
