#include <MLV/MLV_all.h>
#include <stdio.h>

#include "headers/board.h"
#include "headers/sudoku.h"
#include "headers/input_manager.h"
#include "headers/data_reader.h"

void game(Board sudoku, Board inGameSudoku, Board numPad)
{
    int sudokuSize, numSize, position, padPosition;

    sudokuSize = 9;
    numSize = 3;
    
    /* Solve the Sudoku in order to check if user input is OK */
    sudoku_solver(sudoku, 0);

    /* Create numeric pad */
    fill_numeric_pad(numPad);

    /* MLV background */
    MLV_create_window("ｓｕｄｏｋｕ　（よリ哀)", "background", console_WIDTH, console_HEIGHT);

    while(1)
    {
        /* Step 1 : Display the inGame board */
        display_background();
        display_board(inGameSudoku, 9);
        
        MLV_actualise_window();

        position = get_input(sudokuSize);

        if(position == -1)
        {
            MLV_draw_text(600, 30, "out of the board ...\n", MLV_COLOR_MAGENTA);
            MLV_actualise_window();
        }
        else
        {
            padPosition = get_input(numSize);
            
            while(padPosition == -1)
            {
                display_board(numPad, 3);
                MLV_actualise_window();
                padPosition = get_input(numSize);
            }
        }


       /*
        get input

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
        MLV_clear_window(MLV_COLOR_BLACK);
    }
}

void quitGame()
{
    MLV_draw_text(600, 30, "you quit the game!\n", MLV_COLOR_MAGENTA);
    MLV_actualise_window();

    MLV_wait_seconds(5);

    exit(0);
}