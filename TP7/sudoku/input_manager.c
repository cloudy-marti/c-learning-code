#include <MLV/MLV_all.h>
#include <stdio.h>
#include "headers/input_manager.h"
#include "headers/sudoku.h"
#include "headers/board.h"


int get_input(int sudokuSize)
{
	int x = 0;
	int y = 0;

	int position = -1;

    MLV_wait_mouse(&x, &y);
    position = get_box_clicked(x, y, sudokuSize);

    return position;
}

int get_box_clicked(int x, int y, int sudokuSize)
{
	int position = get_position(x, y, sudokuSize);

	if(position == -1)
		return -1;

	return position;
}

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
	{
		printf("not in board\n");
		return -1;
	}

	int tmpX, tmpY;

	tmpX = x - marginLeft;
	tmpY = y - marginTop;

	int row, column;

	row = tmpX / (size/sudokuSize);
	column = tmpY / (size/sudokuSize);

	int position = row*sudokuSize + column;

	printf("position = %d\n", position);

	return position;
}

int input_in_board(int x, int y, int size, int marginTop, int marginLeft)
{
	if(x < marginLeft || x > marginLeft+size || y < marginTop || y > marginTop+size)
		return 0;
	else
		return 1;
}
/*
int which_sudoku(int x, int y)
{
	if(x < 150 && x > 636 && y < 75 && y > 561)
	{
		return 9;
		printf("inside main game board\n");
	}
	else if(x < 750 && x > 990 && y < 200 && y > 440)
	{
		return 3;
		printf("inside numPad\n");
	}
	else
		return -1;
}*/