#include <MLV/MLV_all.h>
#include <stdio.h>

#include "headers/board.h"
#include "headers/sudoku.h"
#include "headers/input_manager.h"
#include "headers/data_reader.h"
#include "headers/turn_manager.h"

void game(Board* sudoku, Board* inGameSudoku, Board* numPad)
{
    int sudokuSize, numSize;
    int position, padPosition;
    int row, column, padRow, padColumn;

    sudokuSize = 9;
    numSize = 3;

    /* Create numeric pad */
    fill_numeric_pad(numPad);

    /* MLV background */
    MLV_create_window("ｓｕｄｏｋｕ　（よリ哀)", "background", console_WIDTH, console_HEIGHT);

    while(1)
    {
        /* Display the background and the inGame board */
        display_background();
        display_board(inGameSudoku, 9);
        
        MLV_actualise_window();

        /* Check if the in-game board is full */
        if(inGameSudoku->empty_counter == 0)
            quit_game();

        /* Get the player's input on the in-game board */
        position = get_input(sudokuSize);

        row = position / sudokuSize;
        column = position - row*sudokuSize;

        /* If player clicks out of the board */
        if(position == -1)
        {
            /* Keep waiting for next move */
            MLV_draw_text(600, 30, "out of the board ...\n", MLV_COLOR_MAGENTA);
            MLV_actualise_window();
        }
        /* If player clicks on an unchangeable case */
        else if(sudoku->board[column][row] != 0)
        {
            /* Keep waiting for next move */
            MLV_draw_text(600, 30, "cannot change value ...\n", MLV_COLOR_MAGENTA);
            MLV_actualise_window();
        }
        else
        {
            padPosition = -1;
            
            while(padPosition == -1)
            {
                /* Display the numeric pad */
                display_board(numPad, 3);
                MLV_actualise_window();
                
                /* Get the player's input on the numeric pad */
                padPosition = get_input(numSize);

                padRow = padPosition / numSize;
                padColumn = padPosition - padRow*numSize;

                /* If the number chosen is safe */
                if(is_safe(inGameSudoku, column, row, numPad->board[padColumn][padRow]))
                {
                    /* If the case was empty before, decrease the empty counter */
                    if(inGameSudoku->board[column][row] == 0)
                        inGameSudoku->empty_counter--;

                    /* Add the chosen number to the in-game board */
                    inGameSudoku->board[column][row] = numPad->board[padColumn][padRow];
                    
                }
            }
        }

        MLV_clear_window(MLV_COLOR_BLACK);
    }
}

void quit_game()
{
    MLV_draw_text(600, 30, "you quit the game!\n", MLV_COLOR_MAGENTA);
    MLV_actualise_window();

    MLV_wait_seconds(5);

    exit(0);
}