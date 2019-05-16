/*#include "../headers/slider.h"
#include "../headers/mlv_board.h"

int get_column(int position)
{
	return position%PUZZLE_SIZE;
}

int get_row(int position)
{
	return position/PUZZLE_SIZE;
}

int get_position_from_coordinates(int row, int column)
{
	return (row*PUZZLE_SIZE) + column;
}

int get_position(int x, int y)
{
	int position = 0;

	x /= (CONSOLE_SIZE / PUZZLE_SIZE);
	y /= (CONSOLE_SIZE / PUZZLE_SIZE);

	position = (y*PUZZLE_SIZE) + x;

	return position;
}*/