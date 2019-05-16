#include <stdio.h>
#include <stdlib.h>

#include "../headers/slider.h"
#include "../headers/slider_helper.h"

/**
 * Initialize board structure and give the number of the boxes
 * Then assign 0 to the last box (which will simulate the empty box)
 */
void initialize_board(Board* board)
{
	int row, column, counter;

	counter = 0;

	for(row = 0; row < PUZZLE_SIZE; ++row)
	{
		for(column = 0; column < PUZZLE_SIZE; ++column)
		{
			board->grid[row][column].row = row;
			board->grid[row][column].column = column;

			board->grid[row][column].data = counter;

			counter++;
		}
	}

	board->grid[row-1][column-1].data = -1;
}

/**
 * Print the board in terminal
 */
void print_board(Board* board)
{
	int row, column;

	for(row = 0; row < PUZZLE_SIZE; row++)
	{
		for(column = 0; column < PUZZLE_SIZE; column++)
			printf("-----");

		printf("-\n");

		for(column = 0; column < PUZZLE_SIZE; column++)
		{
			if((board->grid)[row][column].data == -1)
				printf("|    ");
			else
			{
				if(((board->grid)[row][column]).data >= 10)
					printf("| %d ", ((board->grid)[row][column]).data);
				else
					printf("| %d  ", ((board->grid)[row][column]).data);
			}
		}
		printf("|\n");
	}

	for(row = 0; row < PUZZLE_SIZE; row++)
		printf("-----");

	printf("-\n");
}

/**
 * Return the available box (empty box next to the current box)
 * Return NONE if there is none
 */
Direction check_empty(Board* board, Square box)
{
	if(board->grid[box.row][box.column-1].data == -1)
		return UP;
	if(board->grid[box.row][box.column+1].data == -1)
		return DOWN;
	if(board->grid[box.row+1][box.column].data == -1)
		return RIGHT;
	if(board->grid[box.row-1][box.column].data == -1)
		return LEFT;
	
	return NONE;
}

/**
 * Change the case data, essentially data will go to the direction choosen
 * and current box will be emptied
 */
void move_to(Board* board, Square box, Direction direction)
{
	//printf("data = %d \tboard[%d][%d]\n", board->grid[box.row][box.column].data, box.row, box.column);
	if(direction == NONE)
	{
	//	printf("forbidden move\n");
		return;
	}
	else if(direction == UP)
		board->grid[box.row][box.column-1].data = board->grid[box.row][box.column].data;
	else if(direction == DOWN)
		board->grid[box.row][box.column+1].data = board->grid[box.row][box.column].data;
	else if(direction == RIGHT)
		board->grid[box.row+1][box.column].data = board->grid[box.row][box.column].data;
	else
		board->grid[box.row-1][box.column].data = board->grid[box.row][box.column].data;
	
	board->grid[box.row][box.column].data = -1;
}

/**
 * Calls move_to with the returned value of check_empty
 * If there is an empty adjacent box, the current box will be moved
 * if not, nothing happens
 */
void move_square(Board* board, Square box)
{
	Direction direction = check_empty(board, box);

	//printf("Chosen Direction = %d\tboard[%d][%d]\n", direction, box.row, box.column);

	move_to(board, box, direction);
}

void check_solved_puzzle(Board* board)
{
	if(board->grid[PUZZLE_SIZE-1][PUZZLE_SIZE-1].data != -1)
		/*first check : not solved*/
		return;
}

void update_position(Board* board, int x, int y, int* position, int* counter)
{
	move_square(board, board->grid[x][y]);
	*position = get_position_from_coordinates(x, y);
	(*counter)--;
}

void shuffle(Board* board, int position, int counter)
{
	if(counter == 0)
		return;

	Direction direction = rand()%5;

	int x = get_row(position);
	int y = get_column(position);


	switch(direction)
	{
		case UP :
			y -= 1;

			if(y >= 0)
			{
				update_position(board, x, y, &position, &counter);
			}

			break;

		case DOWN :
			y += 1;

			if(y < PUZZLE_SIZE)
			{
				update_position(board, x, y, &position, &counter);
			}

			break;

		case LEFT :
			x -= 1;

			if(x >= 0)
			{
				update_position(board, x, y, &position, &counter);
			}

			break;

		case RIGHT :
			x += 1;

			if(x < PUZZLE_SIZE)
			{
				update_position(board, x, y, &position, &counter);
			}

			break;

		default :
			break;
	}

	return shuffle(board, position, counter);
}