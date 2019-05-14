#ifndef __SLIDER_H__
#define __SLIDER_H__

#define PUZZLE_SIZE 4
#define SHUFFLE_TIMES 64

typedef struct _square
{
	int row;
	int column;
	int data;
} Square;

typedef struct _board
{
	Square grid[PUZZLE_SIZE][PUZZLE_SIZE];
} Board;

typedef enum _direction
{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT
} Direction;

void initialize_board(Board* board);
void print_board(Board* board);

Direction check_empty(Board* board, Square box);
void move_to(Board* board, Square box, Direction direction);
void move_square(Board* board, Square box);

int get_column(int position);
int get_row(int position);
int get_position_from_coordinates(int row, int column);

#endif