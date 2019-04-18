#include <MLV/MLV_all.h>
#include <stdio.h>
#include <string.h>

#include "../headers/slider.h"
#include "../headers/input_manager.h"
#include "../headers/mlv_board.h"

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		printf("put path of image pls\n");
		return 0;
	}

	Board board;

	initialize_board(&board);
	print_board(&board);

	MLV_create_window("slider puzzle game opa", "background", CONSOLE_SIZE, CONSOLE_SIZE);
	display_picture(&board, argv[1]);
	MLV_actualise_window();

	int input = stdin_scan_input();

	int row = get_row(input);
	int column = get_column(input);

	printf("\nposition = %d\tboard[%d][%d]\n", input, row, column);

	Square chosenBox = board.grid[row][column];

	move_square(&board, chosenBox);

	print_board(&board);
	MLV_clear_window(MLV_COLOR_BLACK);
	display_picture(&board, argv[1]);
	MLV_actualise_window();

	MLV_wait_seconds(10);

	return 0;
}
