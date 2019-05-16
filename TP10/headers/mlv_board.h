#ifndef __MLV_BOARD_H__
#define __MLV_BOARD_H__

#include <MLV/MLV_all.h>

#define CONSOLE_SIZE 512
#define SQUARE_SIZE CONSOLE_SIZE/PUZZLE_SIZE

MLV_Image* load_picture(char* picturePath);
void display_picture(Board* board, MLV_Image* puzzle_pic);

#endif