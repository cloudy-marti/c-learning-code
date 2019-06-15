### Makefile of queens Project ###

CC=gcc
CFLAGS=-Wall -ansi -g -std=c99
OBJ=$(OBJPATH)game.o $(OBJPATH)queens.o $(OBJPATH)mlv_board.o
OBJPATH=obj/
SRCPATH=src/
LDFLAGS=-lMLV -lm

all : queens
	@echo "--------------------------------------------------------------"
	@echo "               queens Game - C Programming"
	@echo "                      Emilie Marti"
	@echo ""
	@echo "               to execute type: ./bin/queens"
	@echo "--------------------------------------------------------------"

queens: $(OBJ)
	$(CC) -o bin/queens $(OBJ) $(LDFLAGS)

$(OBJPATH)game.o: $(SRCPATH)game.c
	$(CC) -c $(SRCPATH)game.c -o $(OBJPATH)game.o $(CFLAGS) -lMLV

$(OBJPATH)queens.o: $(SRCPATH)queens.c
	$(CC) -c $(SRCPATH)queens.c -o $(OBJPATH)queens.o $(CFLAGS) -lMLV

$(OBJPATH)mlv_board.o: $(SRCPATH)mlv_board.c
	$(CC) -c $(SRCPATH)mlv_board.c -o $(OBJPATH)mlv_board.o $(CFLAGS) -lMLV

clean:
	rm -f $(OBJ)
	rm -f ../bin/queens