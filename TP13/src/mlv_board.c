#include <MLV/MLV_all.h>

#include "../headers/checkers.h"
#include "../headers/mlv_board.h"

void display_background()
{
    // MLV_Image *background;
    // int bg_width, bg_height;

    // background = MLV_load_image("data/space.jpeg");

    // //MLV_resize_image_with_proportions(background, CONSOLE_SIZE, CONSOLE_SIZE);
    // //MLV_get_image_size(background, &bg_width, &bg_height);

    // MLV_draw_image(background, 0, 0);
    MLV_Image *background;
    int bg_width, bg_height;

    background = MLV_load_image("data/space.jpg");

    MLV_resize_image_with_proportions(background, CONSOLE_SIZE, CONSOLE_SIZE);
    MLV_get_image_size(background, &bg_width, &bg_height);

    MLV_draw_image(background, 0, 0);
}

void display_board(uint64_t bitboard)
{
    int shape = 75;
    int size = 75*BOARD_SIZE;

    int marginTop = 50;
    int marginLeft = 100;

    int row, column;

    MLV_Color color;

    for(column = 0; column < size; column = column+shape)
    {              
        for(row = 0; row < size; row = row+shape)
        {
        	if((row+column)%2 != 0)
        	{
        		color = MLV_convert_rgba_to_color(225, 225, 175, 125);
        	}
        	else
        	{
        		color = MLV_convert_rgba_to_color(125, 125, 125, 125);
        	}

            MLV_draw_filled_rectangle(row+marginLeft, column+marginTop, shape, shape, color);
        }
    }
}
