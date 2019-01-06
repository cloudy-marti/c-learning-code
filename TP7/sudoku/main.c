#include <MLV/MLV_all.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "headers/board.h"
#include "headers/sudoku.h"
#include "headers/data_reader.h"

int main(int argc, char* argv[])
{
	Board sudoku;

	fread_board(argv[1], sudoku);
	print_board(sudoku);

	game(sudoku);

	MLV_Keyboard_button key;
	MLV_wait_keyboard(&key, NULL, NULL);
	if(key == MLV_KEYBOARD_q) MLV_free_window();

	return 0;
}
