CC=gcc
CFLAGS=-c -fPIC
LIBNAME = labfunc

obj= encryption.o list.o shellsort.o


static: $(obj)
	ar rc lib$(LIBNAME).a $(obj)
	ranlib lib$(LIBNAME).a
dynamic: $(obj)	
	gcc -shared -fPIC -o lib$(LIBNAME).so $(obj)
encryption.o: encryption.c encryption.h
	$(CC) $(CFLAGS) encryption.c
list.o: list.c list.h data.h
	$(CC) $(CFLAGS) list.c
shellsort.o: shellsort.c shellsort.h
	$(CC) $(CFLAGS) shellsort.c
clean: 
	rm $(obj)

