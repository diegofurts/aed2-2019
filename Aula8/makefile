CC=gcc
CFLAGS=-Wall
objects = main.o Lista.o Hash.o

hashing : $(objects)
	$(CC) -o hashing $(objects)

main.o : Lista.h Hash.h
Hash.o : Lista.h

clean :
	rm hashing $(objects)
