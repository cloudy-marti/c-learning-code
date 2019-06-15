#include <MLV/MLV_all.h>

#include "../headers/queens.h"
#include "../headers/mlv_board.h"

void display_background(MLV_Image* background)
{
    MLV_resize_image_with_proportions(background, CONSOLE_SIZE, CONSOLE_SIZE);

    MLV_draw_image(background, 0, 0);
}

void display_board(uint64_t bitboard, MLV_Image* picture)
{
    int shape = 54;

    int marginTop = MARGIN_TOP;
    int marginLeft = MARGIN_LEFT;

    int row, column;
    int counter = BITBOARD_SIZE;
    
    MLV_Color color;
    MLV_resize_image_with_proportions(picture, shape, shape);

    for(row = BOARD_SIZE - 1; row >= 0; --row)
    {
        for(column = 0; column < BOARD_SIZE; column++)
        {
            counter--;

            if((row+column)%2 != 0)
            {
                color = MLV_convert_rgba_to_color(250, 65, 200, 125);
            }
            else
            {
                color = MLV_convert_rgba_to_color(55, 205, 255, 125);
            }
            
            MLV_draw_filled_rectangle((row*shape)+marginLeft, (column*shape)+marginTop, shape, shape, color);
            
            if(bit_value_bitboard(bitboard, counter))
            {
                MLV_draw_image(picture, (row*shape)+marginLeft, (column*shape)+marginTop+(rand()%2));
            }
        }
    }
}

void end_game(MLV_Image* background, MLV_Image* picture)
{
    int index;

    for(index = 54; index <= CONSOLE_SIZE; index += 10)
    {
        display_background(background);
        
        MLV_resize_image_with_proportions(picture, index, index);
        MLV_draw_image(picture, (CONSOLE_SIZE/2) - (index/2), (CONSOLE_SIZE/2) - (index/2));
        
        MLV_actualise_window();
        MLV_clear_window(MLV_COLOR_BLACK);
        
        MLV_wait_milliseconds(50);
    }
}