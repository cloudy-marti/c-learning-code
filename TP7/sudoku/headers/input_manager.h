#ifndef __INPUT_MANAGER__
#define __INPUT_MANAGER__

#include "sudoku.h"

int get_input(int sudokuSize);
int get_position(int x, int y, int sudokuSize);
int input_in_board(int x, int y, int size, int marginTop, int marginLeft);

#endif
