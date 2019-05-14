#include <stdio.h>
#include <MLV/MLV_all.h>

#include "../headers/slider.h"
#include "../headers/mlv_board.h"
#include "../headers/input_manager.h"

int stdin_scan_input()
{
	int input = -1;

	printf("choose a number\n");
	scanf("%d", &input);

	while(input < 0 || input >= PUZZLE_SIZE*PUZZLE_SIZE)
	{
		printf("don't try to break my game\n");
		scanf("%d", &input);
	}

	return input;
}

int click_input()
{
	int x = 0;
	int y = 0;

	int input = -1;

	MLV_wait_mouse(&x, &y);

	input = get_position(x, y);

	return input;
}

int get_position(int x, int y)
{
	int position = 0;

	x /= (CONSOLE_SIZE / PUZZLE_SIZE);
	y /= (CONSOLE_SIZE / PUZZLE_SIZE);

	position = (y*PUZZLE_SIZE) + x;

	return position;
}

void shuffle(Board* board, int position, int counter)
{
	if(counter == 0)
		return;

	Direction direction = rand()%4;

	int x = get_row(position);
	int y = get_column(position);


	switch(direction)
	{
		case UP :
			y -= 1;

			if(y < PUZZLE_SIZE)
			{
				move_square(board, board->grid[x][y]);
				position = get_position_from_coordinates(x, y);
				printf("position = %d\tdirection = %d\tx = %d\ty = %d\n", position, direction, x, y);
				printf("\ngoing DOWN\t position = %d\n\n", position);
				counter--;
			}

			break;

		case DOWN :
			y += 1;

			if(y >= 0)
			{
				move_square(board, board->grid[x][y]);
				position = get_position_from_coordinates(x, y);
				printf("position = %d\tdirection = %d\tx = %d\ty = %d\n", position, direction, x, y);
				printf("\ngoing UP\t position = %d\n\n", position);
				counter--;
			}

			break;

		case LEFT :
			x -= 1;

			if(x < PUZZLE_SIZE)
			{
				move_square(board, board->grid[x][y]);
				position = get_position_from_coordinates(x, y);
				printf("position = %d\tdirection = %d\tx = %d\ty = %d\n", position, direction, x, y);
				printf("\ngoing RIGHT\t position = %d\n\n", position);
				counter--;
			}

			break;

		case RIGHT :
			x += 1;

			if(x >= 0)
			{
				move_square(board, board->grid[x][y]);
				position = get_position_from_coordinates(x, y);
				printf("position = %d\tdirection = %d\tx = %d\ty = %d\n", position, direction, x, y);
				printf("\ngoing LEFT\t position = %d\n\n", position);
				counter--;
			}

			break;

		default :
			break;
	}

	printf("counter = %d\n", counter);

	return shuffle(board, position, counter);
}