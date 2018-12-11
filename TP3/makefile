# Makefile TP 3 INFO1

CC=gcc
CFLAGS=-Wall -ansi -g
FILE = main.c exo1.c exo2.c exo3.c exo4.c exo5.c

all : tp3 clean
	@echo "--------------------------------------------------------------"
	@echo "             Some exercices - C programming TP3"
	@echo "                       Emilie Marti"
	@echo ""
	@echo "                 to execute type: ./TP3"
	@echo "--------------------------------------------------------------"

tp3: $(OBJ)
	$(CC) $(FILE) $(OBJ) $(CFLAGS) -o TP3

clean:
	rm -f *.o

# CFLAGS = -g -Wall
# FILE = game.c board.c playerManagerV2.c turnManager.c unitManager.c

# all: projetC

# projetC: 
# 	gcc $(FILE) $(CFLAGS) -o Game

# tp3: $(OBJ)
# 	$(CC) -c main.c -o TP3 $(OBJ) $(CFLAGS)