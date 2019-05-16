#include <MLV/MLV_all.h>

#include "../headers/slider.h"
#include "../headers/mlv_board.h"
#include "../headers/slider_helper.h"

MLV_Image* load_picture(char* picturePath)
{
	return MLV_load_image(picturePath);
}

void display_picture(Board* board, MLV_Image* puzzle_pic)
{
    int data, picRow, picColumn;
    int row, column;

    for(row = 0; row < PUZZLE_SIZE; ++row)
	{
		for(column = 0; column < PUZZLE_SIZE; ++column)
		{
			data = (board->grid)[row][column].data;
			if(data != -1)
			{
				picRow = get_row(data);
				picColumn = get_column(data);

				MLV_draw_partial_image(	puzzle_pic,
										picColumn*(CONSOLE_SIZE/PUZZLE_SIZE) - 1, picRow*(CONSOLE_SIZE/PUZZLE_SIZE) - 1,
										(CONSOLE_SIZE/PUZZLE_SIZE) - 1, (CONSOLE_SIZE/PUZZLE_SIZE) - 1,
										column*(CONSOLE_SIZE/PUZZLE_SIZE) + 1, row*(CONSOLE_SIZE/PUZZLE_SIZE) + 1);
			}
		}
	}
}

