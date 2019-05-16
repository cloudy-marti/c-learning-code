#include <stdio.h>
#include <stdlib.h>

#include "../headers/checkers.h"
#include "../headers/checkers_helper.h"

int bit_value_bitboard(unsigned long int bitboard, int position)
{
	return bitboard & ((unsigned long int)1 << position);
}

void print_bitboard(unsigned long int bitboard)
{
	int index;

	for(index = BITBOARD_SIZE - 1; index >= 0; --index)
	{
		printf("%c", bit_value_bitboard(bitboard, index)? '1':'0');
		if(index % 8 == 0)
		{
			printf("\n");
		}
	}
	// int row, column;

	// for(row = 0; row < PUZZLE_SIZE; row++)
	// {
	// 	for(column = 0; column < PUZZLE_SIZE; column++)
	// 		printf("-----");

	// 	printf("-\n");

	// 	for(column = 0; column < PUZZLE_SIZE; column++)
	// 	{
	// 		if((board->grid)[row][column].data == -1)
	// 			printf("|    ");
	// 		else
	// 		{
	// 			if(((board->grid)[row][column]).data >= 10)
	// 				printf("| %d ", ((board->grid)[row][column]).data);
	// 			else
	// 				printf("| %d  ", ((board->grid)[row][column]).data);
	// 		}
	// 	}
	// 	printf("|\n");
	// }

	// for(row = 0; row < PUZZLE_SIZE; row++)
	// 	printf("-----");

	// printf("-\n");
}

void set_positive_bit_bitboard(unsigned long int* bitboard, int position)
{

}

void set_negative_bit_bitboard(unsigned long int* bitboard, int position)
{

}