CC = gcc
CFLAGS = -Werror -Wall -pedantic

all : driver test

test : test.o
	$(CC) $(CFLAGS) -o test test.o

test.o :  test.c
	$(CC) $(CFLAGS) -c test.c

driver : main.o list.o
	$(CC) $(CFLAGS) -o driver main.o list.o

main.o : main.c list.h
	$(CC) $(CFLAGS) -c main.c

list.o : list.c list.h
	$(CC) $(CFLAGS) -c list.c

run: all
	leaks --atExit -- ./driver

clean : 
	rm -f *.o driver test