CC=gcc
CFLAGS=-Wall
objects = main.o SkipList.o

lista1 : $(objects)
	$(CC) -o skiplist $(objects)

main.o : SkipList.h
ListaEstatica.o : SkipList.h

clean :
	rm skiplist $(objects)
