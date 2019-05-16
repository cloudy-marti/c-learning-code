#ifndef __SLIDER_H__
#define __SLIDER_H__

#define PUZZLE_SIZE 4
#define SHUFFLE_TIMES 120

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
Board initialize_game();
void print_board(Board* board);

Direction check_empty(Board* board, Square box);
void move_to(Board* board, Square box, Direction direction);
void move_square(Board* board, Square box);

void update_position(Board* board, int x, int y, int* position, int* counter);
void shuffle(Board* board, int position, int counter);

#endif