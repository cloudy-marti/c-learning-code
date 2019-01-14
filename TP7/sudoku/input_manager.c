#include <MLV/MLV_all.h>
#include <stdio.h>
#include "headers/input_manager.h"
#include "headers/board.h"

void get_input(int x, int y)
{
	MLV_Sound* sound;

	sound = MLV_load_sound("sound/blip.ogg");

    /*MLV_get_mouse_position(&x, &y);*/
    MLV_wait_mouse(&x, &y);
	MLV_wait_mouse(&x, &y);

    MLV_get_mouse_position(&x, &y);
    get_box_clicked(x, y, 9);
    get_box_clicked(x, y, 3);
    MLV_draw_text(400, 630, "mouse : (%d, %d)", MLV_COLOR_MAGENTA, x, y);

    MLV_actualise_window();
	
    MLV_draw_circle(x, y, 20, MLV_COLOR_MAGENTA);
    MLV_play_sound(sound, 1.0);
    
}

void trigger_color()
{

}

int get_box_clicked(int x, int y, int sudokuSize)
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

	if(x > marginLeft && row < 9 && y > marginTop && column < 9) printf("marginTop = %d\tmarginLeft = %d\ntmpX = %d\ttmpY = %d\nyou clicked on (%d, %d) which is box [%d, %d] on grid %d\nposition = %d\n", marginTop, marginLeft, tmpX, tmpY, x, y, row, column, sudokuSize, position);

	return position;
}