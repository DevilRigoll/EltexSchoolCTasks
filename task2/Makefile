CC=gcc
CFLAGS=-c

all: Result


Result: main.o dataWorker.o shellsort.o
	$(CC) main.o dataWorker.o shellsort.o -o result
main.o: main.c dataWorker.h shellsort.h
	$(CC) $(CFLAGS) main.c 
shellsort.o: shellsort.c shellsort.h
	$(CC) $(CFLAGS) shellsort.c
dataWorker.o: dataWorker.c dataWorker.h
	$(CC) $(CFLAGS) dataWorker.c
