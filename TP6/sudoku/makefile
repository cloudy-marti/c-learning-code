CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=
OBJ=sudoku.o main.o in_out.o

sudoku: $(OBJ)
	$(CC) -o sudoku $(OBJ) $(CFLAGS)
	@echo "--------------------------------------------------------------"
	@echo "             SUDOKU Solver - C programming TP6"
	@echo "                       Emilie Marti"
	@echo ""
	@echo "                to execute type: ./sudoku"
	@echo "--------------------------------------------------------------"

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

sudoku.o: sudoku.c 
	$(CC) -c sudoku.c $(CFLAGS)

in_out.o: in_out.c 
	$(CC) -c in_out.c $(CFLAGS)

clean: 
	rm -f *.o
	rm -f *~
	rm -f sudoku
