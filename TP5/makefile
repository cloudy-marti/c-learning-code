# Makefile TP 5 INFO1

CC = gcc
CFLAGS = -Wall -ansi -g
OBJ = exo0.o exo1.o exo2.o exo3.o main.o

all : tp5 clean
	@echo "--------------------------------------------------------------"
	@echo "       Integer Arrays Functions - C programming TP5"
	@echo "                       Emilie Marti"
	@echo ""
	@echo "                 to execute type: ./TP5"
	@echo "--------------------------------------------------------------"

main.o :
	gcc $(CFLAGS) -c main.c

exo0.o :
	gcc $(CFLAGS) -c exo0.c

exo1.o :
	gcc $(CFLAGS) -c exo1.c

exo2.o :
	gcc $(CFLAGS) -c exo2.c

exo3.o :
	gcc $(CFLAGS) -c exo3.c

tp5 : $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o TP5

clean :
	rm -f *.o