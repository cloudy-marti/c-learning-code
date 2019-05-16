#include <MLV/MLV_all.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../headers/slider.h"
#include "../headers/input_manager.h"
#include "../headers/mlv_board.h"
#include "../headers/slider_helper.h"

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		printf("put path of image pls\n");
		return 0;
	}

	Board board;

	srand(time(NULL));

	initialize_board(&board);
	shuffle(&board, (PUZZLE_SIZE*PUZZLE_SIZE)-1, SHUFFLE_TIMES);
		
	MLV_create_window("ｓｌｉｄｅｒ  ｐｕｚｚｌｅ  ｏｐａ　（ヶ因流)", "background", CONSOLE_SIZE, CONSOLE_SIZE);

	MLV_Image* picture = load_picture(argv[1]);

	int running = 1;

	while(running)
	{
		display_picture(&board, picture);
		MLV_actualise_window();

		int input = click_input();

		int row = get_row(input);
		int column = get_column(input);

		Square chosenBox = board.grid[row][column];

		if(chosenBox.data != -1)
		{
			move_square(&board, chosenBox);
		}
		
		MLV_clear_window(MLV_COLOR_BLACK);
	}

	return 0;
}
