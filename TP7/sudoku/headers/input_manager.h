#ifndef __INPUT_MANAGER__
#define __INPUT_MANAGER__

#include "sudoku.h"

void get_input(Board sudoku, Board inGame, Board numPad, int x, int y);
int get_box_clicked(Board sudoku, Board inGame, Board numPad, int x, int y);
int get_position(int x, int y, int sudokuSize);
void trigger_color();


#endif
