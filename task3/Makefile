CC=gcc
CFLAGS=-c

all: Result

static: dataWorker.o main.c
	$(CC) -o statResult main.c dataWorker.o -L. -llabfunc
staticso: dataWorker.o main.c
	$(CC) -o statResult main.c dataWorker.o -L. -llabfuncdll
dynamic: dataWorker.o main.c
	$(CC) -o dynamicResult maindynamic.c dataWorker.o -ldl
		

Result: main.o dataWorker.o list.o
	$(CC) -o result main.o dataWorker.o list.o
main.o: main.c dataWorker.h list.h data.h
	$(CC) $(CFLAGS) main.c 
list.o: list.c list.h data.h
	$(CC) $(CFLAGS) list.c
dataWorker.o: dataWorker.c dataWorker.h
	$(CC) $(CFLAGS) dataWorker.c
