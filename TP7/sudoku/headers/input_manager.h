#ifndef __INPUT_MANAGER__
#define __INPUT_MANAGER__

#include "sudoku.h"

/*void get_input(Board sudoku, Board inGame, Board numPad);
int get_box_clicked(Board inGame, Board numPad, int x, int y);
int get_position(int x, int y);*/
int get_input(int sudokuSize);
int get_box_clicked(int x, int y, int sudokuSize);
int get_position(int x, int y, int sudokuSize);
int input_in_board(int x, int y, int size, int marginTop, int marginLeft);

#endif
