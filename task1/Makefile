CC=gcc
CFLAGS=-c

all: Result


Result: main.o dataWorker.o encryption.o
	$(CC) main.o dataWorker.o encryption.o -o result
main.o: main.c dataWorker.h encryption.h
	$(CC) $(CFLAGS) main.c 
encryption.o: encryption.c encryption.h
	$(CC) $(CFLAGS) encryption.c
dataWorker.o: dataWorker.c dataWorker.h
	$(CC) $(CFLAGS) dataWorker.c
