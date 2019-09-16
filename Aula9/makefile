CC=gcc
CFLAGS=-Wall
objects = 2sum.o Lista.o Hash.o

2sum : $(objects)
	$(CC) -o 2sum $(objects)

2sum.o : Lista.h Hash.h
Hash.o : Lista.h
Lista.o : Lista.h

clean :
	rm 2sum $(objects)
