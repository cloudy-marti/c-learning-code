#include <MLV/MLV_all.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include "../headers/queens.h"
#include "../headers/mlv_board.h"

int main(int argc, char** argv)
{
	printf("size of uint64_t = %ld\n", sizeof(uint64_t));

	uint64_t bitboard = 0;

	print_bitboard_board(bitboard);
	int input = 0;

    MLV_create_window("8 dames", "background", CONSOLE_SIZE, CONSOLE_SIZE);
    int counter = 0;

    MLV_Image* background = MLV_load_image("data/vapor.jpg");
    MLV_Image* doggy = MLV_load_image("data/dog.png");

    srand(time(NULL));

    while(1)
    {
		display_background(background);
	    display_board(bitboard, doggy);

	    MLV_actualise_window();

    	if(counter == 8)
    	{
    		end_game(background, doggy);
    		printf("you won omg\n");
    		MLV_wait_seconds(5);
    		break;
    	}

		printf("where are you going to put the lady ?\n");
		scanf("%d", &input);

		int ladyMask = set_lady_mask(&bitboard, input);
		printf("%s\n", ladyMask ? "yes !":"nop");

		if(ladyMask)
		{
			bitboard = set_positive_bit_bitboard(bitboard, input);
			counter++;
		}
		else
		{
			printf("cannot put lady here\n");
		}

		print_bitboard_board(bitboard);
		MLV_wait_milliseconds(200);

    	MLV_clear_window(MLV_COLOR_BLACK);
    }

	return 0;
}