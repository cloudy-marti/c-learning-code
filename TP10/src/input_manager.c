#include <stdio.h>

#include "../headers/slider.h"

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