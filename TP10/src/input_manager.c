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