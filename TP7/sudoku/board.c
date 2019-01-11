#include <MLV/MLV_all.h>
#include <stdio.h>

#include "headers/board.h"
#include "headers/sudoku.h"
#include "headers/input_manager.h"

void game(Board sudoku)
{
    MLV_Image *background;
    int bg_width, bg_height;

    MLV_create_window("ｓｕｄｏｋｕ　（よリ哀)", "background", console_WIDTH, console_HEIGHT);
    background = MLV_load_image("img/vapor.jpeg");

    MLV_resize_image_with_proportions(background, console_WIDTH, console_HEIGHT);
    MLV_get_image_size(background, &bg_width, &bg_height);

    MLV_draw_image(background, 0, 0);

    MLV_init_audio();

    while(1)
    {

        MLV_Keyboard_button key;
        if(key == MLV_KEYBOARD_q) MLV_free_window();

        MLV_draw_text(10, 500, "mlv suck/s", MLV_COLOR_MAGENTA);
        MLV_draw_text(10, 630, "click on the screen pls", MLV_COLOR_MAGENTA);

        display_board(sudoku, 9);
        display_board(sudoku, 3);

        
        

        int x, y;
        x = y = 0;

        get_input(x, y);

        MLV_actualise_window();

        MLV_wait_seconds(1);

        MLV_clear_window(MLV_COLOR_BLACK);
        MLV_draw_image(background, 0, 0);

        /*sudoku_solver(sudoku, 0);

        display_board(sudoku, 9);
        display_board(sudoku, 3);*/

        /*

        etapes :
        On affiche le board de debut
            MLV_actualise_window
        Le joueur clicke sur grid 9
        grid 3 apparait
            MLV_actualise_window
        joueur click sur grid 3
        Le coup est-t-il valide (pas d'incoherences)
            oui -> MLV_actualise_window avec grid 9 mise a jour && grid 3 disparait
            non -> MLV_actualise_window avec message d'erreur
        

        La boucle principale n'a pas MLV_actualise_window, mais les fonctions graphiques
        */
    }
}

void display_board(Board sudoku, int sudokuSize)
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
                write_number(sudoku[counter/sudokuSize][counter%sudokuSize], row+marginLeft+shape/2, column+marginTop+shape/2);
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
    char number_MLV[2];

    number_MLV[0] = number + '0';
    number_MLV[1] = '\0';

    MLV_draw_text(x, y, number_MLV, MLV_COLOR_GREY);
}

void quitGame()
{
    MLV_draw_text(600, 30, "you quit the game!\n", MLV_COLOR_MAGENTA);
    MLV_actualise_window();

    exit(0);
}