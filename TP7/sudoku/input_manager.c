#include <MLV/MLV_all.h>
#include <stdio.h>

void get_input(int x, int y)
{
	MLV_Sound* sound;

	sound = MLV_load_sound("sound/blip.ogg");

    MLV_get_mouse_position(&x, &y);
    MLV_draw_text(400, 630, "mouse : (%d, %d)", MLV_COLOR_MAGENTA, x, y);
	
    /*MLV_draw_circle(x, y, 20, MLV_COLOR_MAGENTA);
    MLV_play_sound(sound, 1.0);*/
    
}

void trigger_color()
{

}