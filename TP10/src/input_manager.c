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

int click_input(Board* board)
{
	MLV_event event;
	MLV_Mouse_button click;

	event = MLV_get_event(NULL, NULL, NULL, NULL, NULL, NULL, &click, NULL);

	if(event == MLV_NONE)
		return 0;

	if(MLV_get_keyboard_state(key) == MLV_PRESSED)
		move_to();

	return 1;
}

void 