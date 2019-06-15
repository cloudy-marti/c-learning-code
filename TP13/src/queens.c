#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../headers/queens.h"

int bit_value_bitboard(uint64_t bitboard, int position)
{
	return (bitboard >> position) & 0x01ul;
}

void print_bitboard(uint64_t bitboard)
{
	int index;

	for(index = BITBOARD_SIZE - 1; index >= 0; --index)
	{
		printf("%c", bit_value_bitboard(bitboard, index)? '1':'0');

		if(index % 4 == 0)
		{
			if(index % 8 == 0)
			{
				printf("\n");
			}
			else
			{
				printf(" ");
			}
		}
	}
}

void print_bitboard_board(uint64_t bitboard)
{
	int row, column;

	int counter = BITBOARD_SIZE;

	for(row = BOARD_SIZE - 1; row >= 0; --row)
	{
		for(column = 0; column < BOARD_SIZE; column++)
		{
			printf("----");
		}

		printf("-\n");

		for(column = 0; column < BOARD_SIZE; column++)
		{
			counter--;

			printf("| %c ", bit_value_bitboard(bitboard, counter)? '1':'0');
		}
		printf("|\n");
	}

	for(row = 0; row < BOARD_SIZE; row++)
	{
		printf("----");
	}

	printf("-\n");
}

uint64_t set_positive_bit_bitboard(uint64_t bitboard, int position)
{
	uint64_t newBitboard = bitboard | (0x01ul << position);

	return newBitboard;
}

uint64_t set_negative_bit_bitboard(uint64_t bitboard, int position)
{
	uint64_t newBitboard = bitboard &= ~(0x01ul << position);

	return newBitboard;
}

int set_lady_mask(uint64_t* bitboard, int ladyPosition)
{
	int ladyByte = ladyPosition / BOARD_SIZE;
	int ladyPositionInByte = ladyPosition % BOARD_SIZE;

	int index;

	for(index = 0; index < BOARD_SIZE; ++index)
	{
		int currentByte = index * BOARD_SIZE;
		int bit;
		/**
		 * Horizontal
		 */
		bit = (ladyByte*BOARD_SIZE) + index;

		if(bit_value_bitboard(*bitboard, bit) && bit != ladyPosition)
		{
			printf("horizontal fails\n");
			return 0;
		}

		/**
		 * Vertical
		 */
		bit = currentByte + ladyPositionInByte;

		if(bit_value_bitboard(*bitboard, bit) && bit != ladyPosition)
		{
			printf("vertical fails\n");
			return 0;
		}

		/**
		 * Diagonal
		 */
		int tmp = (currentByte/BOARD_SIZE) - ladyByte;

		/**
		 * Slash Diagonal (/)
		 */
		bit = currentByte + ladyPositionInByte + tmp;
		
		if(slash_bound(bit) == slash_bound(ladyPosition))
		{
			if(bit_value_bitboard(*bitboard, bit) && bit != ladyPosition)
			{
				printf("slash fails\n");
				return 0;
			}
		}

		/**
		 * AntiSlash Diagonal (\)
		 */
		bit = currentByte + ladyPositionInByte - tmp;

		if(antislash_bound(bit) == antislash_bound(ladyPosition))
		{
			if(bit_value_bitboard(*bitboard, bit) && bit != ladyPosition)
			{
				printf("antislash fails\n");
				return 0;
			}
		}
	}

	return 1;
}

/**
 * Bits in the same diagonal share some properties
 * We use a simple mathematical check to see if the bit we want to set is in the diagonal
 */
int slash_bound(int ladyPosition)
{
	return get_row(ladyPosition) - get_column(ladyPosition);
}

int antislash_bound(int ladyPosition)
{
	return get_row(ladyPosition) + get_column(ladyPosition);
}

int get_column(int position)
{
	return position%BOARD_SIZE;
}

int get_row(int position)
{
	return position/BOARD_SIZE;
}