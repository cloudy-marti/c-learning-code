#include <MLV/MLV_all.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include "../headers/checkers.h"
#include "../headers/mlv_board.h"

int main(int argc, char** argv)
{
	printf("size of uint64_t = %ld\n", sizeof(uint64_t));
	uint64_t bitboard = 0;

	print_bitboard_board(bitboard);
	int input = 0;

	printf("where are you going to put the lady ?\n");
	scanf("%d", &input);

	set_lady_mask(&bitboard, input);
	print_bitboard_board(bitboard);

    MLV_create_window("8 dames", "background", CONSOLE_SIZE, CONSOLE_SIZE);

    while(1)
    {
    	MLV_clear_window(MLV_COLOR_BLACK);

	    display_background();
	    display_board(bitboard);

	    MLV_actualise_window();
		MLV_wait_seconds(5);
    }

	return 0;
}
