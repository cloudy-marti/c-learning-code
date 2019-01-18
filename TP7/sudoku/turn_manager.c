#include <MLV/MLV_all.h>
#include <stdio.h>

#include "headers/board.h"

void manage_turn(Board* sudoku)
{
	while(1)
	{
		display_board(sudoku, 9)
		MLV_actualise_window();

		next_turn();
	}
}



void next_turn()
{

}