CC = gcc
CFLAGS = -Werror -Wall -pedantic

all : driver

test : test.o list.o
	$(CC) $(CFLAGS) -o test test.o list.o node.o

test.o : test.c list.h
	$(CC) $(CFLAGS) -c test.c

driver : main.o list.o node.o
	$(CC) $(CFLAGS) -o driver main.o list.o node.o

main.o : main.c list.h
	$(CC) $(CFLAGS) -c main.c

list.o : list.c list.h node.h
	$(CC) $(CFLAGS) -c list.c

node.o : node.c node.h
	$(CC) $(CFLAGS) -c node.c

run: all
	leaks --atExit -- ./driver
run_test: all
	leaks --atExit -- ./test

clean : 
	rm -f *.o driver test