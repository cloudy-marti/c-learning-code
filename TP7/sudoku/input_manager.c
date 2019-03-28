#include <MLV/MLV_all.h>
#include <stdio.h>
#include "headers/input_manager.h"
#include "headers/sudoku.h"
#include "headers/board.h"

/* Gets player's input and return the position of the case clicked */
int get_input(int sudokuSize)
{
	int x = 0;
	int y = 0;

	int position = -1;

    MLV_wait_mouse(&x, &y);
    position = get_position(x, y, sudokuSize);

    return position;
}

/* Gets the position of the box from mouse_Y and mouse_Y */
/* Returns -1 if sudokuSize is wrong (programmer's fault) or click is out of the board */
int get_position(int x, int y, int sudokuSize)
{
	int marginTop, marginLeft, size;

	if(sudokuSize == 9)
	{
		size = 486;
		marginTop = 75;
		marginLeft = 150;
	}
	else if(sudokuSize == 3)
	{
		size = 240;
		marginTop = 200;
		marginLeft = 750;
	}
	else
		return -1;

	int checkInput = input_in_board(x, y, size, marginTop, marginLeft);

	if(!checkInput)
		return -1;

	int tmpX, tmpY;

	tmpX = x - marginLeft;
	tmpY = y - marginTop;

	int row, column;

	row = tmpX / (size/sudokuSize);
	column = tmpY / (size/sudokuSize);

	int position = row*sudokuSize + column;

	return position;
}

/* Checks whether the click is inside the board or not */
int input_in_board(int x, int y, int size, int marginTop, int marginLeft)
{
	if(x < marginLeft || x > marginLeft+size || y < marginTop || y > marginTop+size)
		return 0;
	else
		return 1;
}