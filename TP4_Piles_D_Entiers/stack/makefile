# Makefile TP 4 INFO1

CC=gcc
CFLAGS=-Wall -ansi -g
OBJ=stack.o main.o
LDFLAGS=-lMLV -lm

all : stack clean
	@echo "--------------------------------------------------------------"
	@echo "             Integers Stack - C programming TP4"
	@echo "                       Emilie Marti"
	@echo ""
	@echo "                 to execute type: ./stack"
	@echo "--------------------------------------------------------------"

stack: $(OBJ)
	$(CC) -o stack $(OBJ) $(LDFLAGS)

stack.o: stack.c stack.h
	$(CC) -c stack.c -o stack.o $(CFLAGS)

main.o: main.c stack.h
	$(CC) -c main.c -o main.o $(CFLAGS)

clean:
	rm -f *.o