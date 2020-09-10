CC=gcc
CFLAGS=-I. -std=c99 -g
DEPS = xsort.h test_data.h
OBJ = main.o xsort.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

xsort: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
