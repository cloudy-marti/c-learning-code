#ifndef __MLV_BOARD_H__
#define __MLV_BOARD_H__

#define CONSOLE_SIZE 800
#define MARGIN_TOP 35
#define MARGIN_LEFT 185

void display_background(MLV_Image* background);
void display_board(uint64_t bitboard, MLV_Image* picture);
void end_game(MLV_Image* background, MLV_Image* picture);

#endif