#include <MLV/MLV_all.h>
#include <stdio.h>

#include "headers/board.h"
#include "headers/sudoku.h"
#include "headers/input_manager.h"

void display_background()
{
    MLV_Image *background;
    int bg_width, bg_height;

    background = MLV_load_image("img/vapor.jpeg");

    MLV_resize_image_with_proportions(background, console_WIDTH, console_HEIGHT);
    MLV_get_image_size(background, &bg_width, &bg_height);

    MLV_draw_image(background, 0, 0);
}

void display_board(Board* sudoku, int sudokuSize)
{
    int row, column, size, marginTop, marginLeft;

    if(sudokuSize == 9)
    {
        size = 486;
        marginTop = 75;
        marginLeft = 150;
    }
    else
    {
        size = 240;
        marginTop = 200;
        marginLeft = 750;
    }

    int shape = size/(sudokuSize);
    int counter = 0;

    for(column = 0; column < size; column = column+shape)
    {              
        for(row = 0; row < size; row = row+shape)
        {
            MLV_draw_rectangle(row+marginLeft, column+marginTop, shape, shape, MLV_COLOR_GREY);

            if(sudokuSize == 9)
            {
                write_number(sudoku->board[counter/sudokuSize][counter%sudokuSize], row+marginLeft+shape/2, column+marginTop+shape/2);
                counter++;
            }
            else
            {
                counter++;
                write_number(counter, row+marginLeft+shape/2, column+marginTop+shape/2);
            }
        }
    }

    MLV_actualise_window();
}

void write_number(int number, int x, int y)
{
    if(number == 0)
        return;

    char number_MLV[2];

    number_MLV[0] = number + '0';
    number_MLV[1] = '\0';

    MLV_draw_text(x, y, number_MLV, MLV_COLOR_GREY);
}

void animate_writing(char* str)
{
    int i;

    char char_MLV[2];

    for(i = 0; str[i] != '\0'; ++i)
    {
        char_MLV[0] = str[i];
        char_MLV[1] = '\0';

        MLV_draw_text(100 + (i*10), 630, char_MLV, MLV_COLOR_MAGENTA);
        MLV_actualise_window();
        MLV_wait_milliseconds(100);
    }

    MLV_wait_milliseconds(300);
}

void display_time(int time)
{
    int seconds = time;
    int minutes = seconds / 60;
    /* Get Hours */
    int hours = minutes / 60;
    /* Get Minutes */
    minutes = seconds - (hours * 60);
    /* Get Seconds */
    seconds = seconds - (hours * 3600) - (minutes * 60);

    hours = 0;
    minutes = 0;
    seconds = time;

    char clock_MLV[24];
    sprintf(clock_MLV, "%02d:%02d:%02d", hours, minutes, seconds);

    MLV_draw_text(600, 630, clock_MLV, MLV_COLOR_MAGENTA);
}