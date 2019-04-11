#include <stdio.h>
#include <stdlib.h>

#define console_WIDTH 512
#define console_HEIGHT 512

#define NB_COL 4
#define NB_ROW 4

typedef struct _square
{
	int row;
	int column;
	int data;
} Square;

typedef struct _board
{
	Square grid[NB_COL][NB_ROW];
} Board;

typedef enum _direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	FORBIDDEN
} Direction;

void initialize_board(Board* board)
{
	int row, column, counter;

	counter = 1;

	for(row = 0; row < NB_ROW; ++row)
	{
		for(column = 0; column < NB_COL; ++column)
		{
			((board->grid)[row][column]).row = row;
			((board->grid)[row][column]).column = column;

			((board->grid)[row][column]).data = counter;

			counter++;
		}
	}

	(board->grid)[NB_ROW-1][NB_COL-1] = NULL;;
}

void print_board(Board* board)
{
	int row, column;

	for(row = 0; row < NB_ROW; row++)
	{
		for(column = 0; column < NB_COL; column++)
			printf("-----");

		printf("-\n");

		for(column = 0; column < NB_COL; column++)
		{
			if((board->grid)[row][column] == NULL)
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

	for(row = 0; row < NB_ROW; row++)
		printf("-----");

	printf("-\n");
}

void move_square(Square* box)
{
	direction = check_empty(box);

	move_to(grid, box, direction);
}

void move_to(Board* board, Square* box, Direction direction)
{
	if(direction == UP)
		board[box->row][box->column-1] = board[box->row][box->column];
	if(direction == DOWN)
		board[box->row][box->column+1] = board[box->row][box->column];
	if(direction == RIGHT)
		board[box->row+1][box->column] = board[box->row][box->column];
	if(direction == LEFT)
		board[box->row-1][box->column] = board[box->row][box->column];
	
	board[box->row][box->column] = NULL;
}

Direction check_empty(Board* board, Square* box)
{

}

int main(int argc, char** argv)
{
	Board* board = (Board*)malloc(sizeof(Board));

	initialize_board(board);
	print_board(board);

	return 0;
}