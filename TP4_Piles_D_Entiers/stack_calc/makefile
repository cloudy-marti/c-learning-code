# Makefile TP 4 INFO1

CC=gcc
CFLAGS=-Wall -ansi -g
OBJ=stack.o interface.o main.o operation.o
LDFLAGS=-lMLV -lm

all : calc clean
	@echo "--------------------------------------------------------------"
	@echo "             Integers Stack - C programming TP4"
	@echo "                       Emilie Marti"
	@echo ""
	@echo "                 to execute type: ./calc"
	@echo "--------------------------------------------------------------"

calc: $(OBJ)
	$(CC) -o calc $(OBJ) $(LDFLAGS)

stack.o: stack.c stack.h
	$(CC) -c stack.c -o stack.o $(CFLAGS)

interface.o: interface.c interface.h stack.h
	$(CC) -c interface.c -o interface.o $(CFLAGS) -lMLV

operation.o: operation.h operation.c stack.h interface.h
	$(CC) -c operation.c -o operation.o $(CFLAGS) -lm

main.o: main.c stack.h interface.h operation.h
	$(CC) -c main.c -o main.o $(CFLAGS)

clean:
	rm -f *.o