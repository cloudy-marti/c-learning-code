#include <MLV/MLV_all.h>
#include <stdio.h>
#include "headers/input_manager.h"
#include "headers/sudoku.h"
#include "headers/board.h"

void get_input(Board sudoku, Board inGame, Board numPad, int x, int y)
{
/*	MLV_Sound* sound;

	sound = MLV_load_sound("sound/blip.ogg");
*/
    /*MLV_get_mouse_position(&x, &y);*/
/*	MLV_wait_mouse(&x, &y);

    MLV_wait_mouse_position(&x, &y);*/

    /* if clicked on indicator --> function_indicator
    	else --> get box clicked*/

    /*get_box_clicked(x, y, 3);*/

/*    MLV_draw_text(400, 630, "mouse : (%d, %d)", MLV_COLOR_MAGENTA, x, y);
*/
	
   /* MLV_draw_circle(x, y, 20, MLV_COLOR_MAGENTA);
    MLV_play_sound(sound, 1.0);*/
    MLV_wait_mouse(&x, &y);
    get_box_clicked(sudoku, inGame, numPad, x, y);
    MLV_actualise_window();
    
}

void trigger_color()
{

}

int get_box_clicked(Board sudoku, Board inGame, Board numPad/*, Board* nb 123456789*/, int x, int y)
{
	int position = get_position(x, y, 9);

	int row = position/9;
	int column = position%9;
	
	if(sudoku[row][column] == 0)
	{
		int x2, y2, nbBox;

		display_board(numPad, 3);
		MLV_actualise_window();

		MLV_wait_mouse(&x2, &y2);
		nbBox = get_position(x2, y2, 3);

		int row2 = nbBox/9;
		int column2 = nbBox%9;

		int chosenNum = numPad[row2][column2];

		if(is_safe(inGame, row, column, chosenNum)) inGame[row][column] = chosenNum;
		else return -1;
		/*get box clicked on grig 3*/

		/*if(is_safe(sudoku, sudoku[x]row, sudoku[y], nb[x][y])) --> affecte la valeur a sudoku
		else erreur :(*/
	}
	else
	{

	}

	return position;
}

int get_position(int x, int y, int sudokuSize)
{
	int marginTop, marginLeft, boxSize;

	if(sudokuSize == 9)
	{
		marginTop = 75;
		marginLeft = 150;
		boxSize = 54;
	}
	else if(sudokuSize == 3)
	{
		marginTop = 200;
		marginLeft = 750;
		boxSize = 80;
	}
	else return -1;

	int tmpX, tmpY;

	tmpX = x - marginLeft;
	tmpY = y - marginTop;

	int row, column;

	row = tmpX / boxSize;
	column = tmpY / boxSize;

	int position = row*9 + column;

	return position;
}