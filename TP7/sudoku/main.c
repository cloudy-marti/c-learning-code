#include <MLV/MLV_all.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "headers/board.h"
#include "headers/sudoku.h"
#include "headers/data_reader.h"

int main(int argc, char* argv[])
{
	Board sudoku, inGame, numPad;

	fread_board(argv[1], sudoku);
	fread_board(argv[1], inGame);
	fill_numeric_pad(numPad);

	print_board(inGame);

	game(sudoku, inGame, numPad);

	return 0;
}
