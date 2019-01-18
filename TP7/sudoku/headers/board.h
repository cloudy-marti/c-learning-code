#ifndef __BOARD__
#define __BOARD__

#define console_WIDTH 1080
#define console_HEIGHT 720

#include "sudoku.h"

void game(Board sudoku, Board inGame, Board numPad);
void display_board(Board sudoku, int sudokuSize);
void write_number(int number, int x, int y);

#endif
