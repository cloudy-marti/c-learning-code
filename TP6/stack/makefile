# Makefile TP6 INFO1

CC = gcc
CFLAGS = -Wall -ansi
OBJ = main.o stack.o

all : stack
	@echo "--------------------------------------------------------------"
	@echo "             Stack Height - C programming TP6"
	@echo "                       Emilie Marti"
	@echo ""
	@echo "                to execute type: ./stack"
	@echo "--------------------------------------------------------------"

main.o:
	$(CC) $(CFLAGS) -c main.c

stack.o:
	$(CC) $(CFLAGS) -c stack.c 

stack: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o stack

clean: 
	rm -f *.o
	rm -f *~
	rm -f stack
