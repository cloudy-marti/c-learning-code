#ifndef __TURN_MANAGER__
#define __TURN_MANAGER__

#define NUMBER_OF_LIVES 3

void game(Board* sudoku, Board* inGameSudoku, Board* numPad);
void win_the_game();
void quit_game();

#endif