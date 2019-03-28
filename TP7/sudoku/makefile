# Makefile TP 7 INFO1

CC=gcc
CFLAGS=-Wall -ansi -g
OBJ=board.o input_manager.o main.o sudoku.o data_reader.o turn_manager.o
LDFLAGS=-lMLV -lm

all : sudoku clean
	@echo "--------------------------------------------------------------"
	@echo "             Graphical SUDOKU - C programming TP7"
	@echo "                       Emilie Marti"
	@echo ""
	@echo "                 to execute type: ./sudoku"
	@echo "--------------------------------------------------------------"

sudoku: $(OBJ)
	$(CC) -o sudoku $(OBJ) $(LDFLAGS)

board.o: board.c
	$(CC) -c board.c -o board.o $(CFLAGS) -lMLV

input_manager.o: input_manager.c
	$(CC) -c input_manager.c -o input_manager.o $(CFLAGS) -lMLV

turn_manager.o: turn_manager.c
	$(CC) -c turn_manager.c -o turn_manager.o $(CFLAGS) -lMLV

sudoku.o: sudoku.c
	$(CC) -c sudoku.c $(CFLAGS)

data_reader.o: data_reader.c
	$(CC) -c data_reader.c $(CFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

clean:
	rm -f *.o