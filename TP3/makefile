# Makefile TP 3 INFO1

CC=gcc
CFLAGS=-Wall -ansi -g

all : calc clean
	@echo "--------------------------------------------------------------"
	@echo "             Some exercices - C programming TP3"
	@echo "                       Emilie Marti"
	@echo ""
	@echo "                 to execute type: ./tp3"
	@echo "--------------------------------------------------------------"

tp3: $(OBJ)
	$(CC) -c main.c -o tp3 $(OBJ) $(CFLAGS)

clean:
	rm -f *.o