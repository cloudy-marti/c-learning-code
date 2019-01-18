#ifndef __DATA_READER__
#define __DATA_READER__

#include "sudoku.h"

int fread_board(const char* file, Board board);
void fill_numeric_pad(Board pad);

#endif
