### Makefile of checkers Project ###

CC=gcc
CFLAGS=-Wall -ansi -g -std=c99
OBJ=$(OBJPATH)game.o $(OBJPATH)checkers.o $(OBJPATH)input_manager.o $(OBJPATH)mlv_board.o $(OBJPATH)checkers_helper.o
OBJPATH=obj/
SRCPATH=src/
LDFLAGS=-lMLV -lm

all : checkers
	@echo "--------------------------------------------------------------"
	@echo "               Checkers Game - C Programming"
	@echo "                      Emilie Marti"
	@echo ""
	@echo "           to execute type: ./bin/checkers data/pic"
	@echo "--------------------------------------------------------------"

checkers: $(OBJ)
	$(CC) -o bin/checkers $(OBJ) $(LDFLAGS)

$(OBJPATH)game.o: $(SRCPATH)game.c
	$(CC) -c $(SRCPATH)game.c -o $(OBJPATH)game.o $(CFLAGS) -lMLV

$(OBJPATH)checkers.o: $(SRCPATH)checkers.c
	$(CC) -c $(SRCPATH)checkers.c -o $(OBJPATH)checkers.o $(CFLAGS) -lMLV

$(OBJPATH)input_manager.o: $(SRCPATH)input_manager.c
	$(CC) -c $(SRCPATH)input_manager.c -o $(OBJPATH)input_manager.o $(CFLAGS) -lMLV

$(OBJPATH)mlv_board.o: $(SRCPATH)mlv_board.c
	$(CC) -c $(SRCPATH)mlv_board.c -o $(OBJPATH)mlv_board.o $(CFLAGS) -lMLV

$(OBJPATH)checkers_helper.o: $(SRCPATH)checkers_helper.c
	$(CC) -c $(SRCPATH)checkers_helper.c -o $(OBJPATH)checkers_helper.o $(CFLAGS) -lMLV

clean:
	rm -f $(OBJ)
	rm -f ../bin/checkers