#include <MLV/MLV_all.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "headers/board.h"
#include <MLV/MLV_all.h>

#include "headers/sudoku.h"
#include "headers/data_reader.h"
#include "headers/turn_manager.h"

int main(int argc, char* argv[])
{
	Board* sudoku, *inGame, *numPad;

	sudoku = initialize_board(9);
	inGame = initialize_board(9);
	numPad = initialize_board(3);

	initialize_empty_board(sudoku, 9);
	initialize_empty_board(inGame, 9);
	initialize_empty_board(numPad, 3);

	fread_board(argv[1], sudoku);
	fread_board(argv[1], inGame);

	game(sudoku, inGame, numPad);

	return 0;
}
