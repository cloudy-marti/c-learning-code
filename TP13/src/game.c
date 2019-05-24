#include <MLV/MLV_all.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include "../headers/checkers.h"

int main(int argc, char** argv)
{
	printf("size of uint64_t = %ld\n", sizeof(uint64_t));
	uint64_t bitboard = 0;

	/* 0xFFFFFFFFFFFFFFFF */

	print_bitboard_board(bitboard);
	int input = 0;

	printf("where are you going to put the lady ?\n");
	scanf("%d", &input);

	/*while(input != -1)
	{

		bitboard = set_positive_bit_bitboard(bitboard, input);

	}*/


	set_lady_mask(&bitboard, input);
	print_bitboard_board(bitboard);

	return 0;
}
