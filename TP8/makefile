# Makefile TP 8 INFO1

CC = gcc
CFLAGS = -Wall -ansi
OBJ = syracuse.o main.o

all : tp8 clean
	@echo "--------------------------------------------------------------"
	@echo "         Syracuse Challenge - C programming TP8"
	@echo "                       Emilie Marti"
	@echo ""
	@echo "                 to execute type: ./TP8"
	@echo "--------------------------------------------------------------"

main.o :
	gcc $(CFLAGS) -c main.c

syracuse.o :
	gcc $(CFLAGS) -c syracuse.c

tp8 : $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o TP8

clean :
	rm -f *.o