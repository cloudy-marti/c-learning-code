#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../headers/checkers.h"
#include "../headers/checkers_helper.h"

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

void set_lady_mask(uint64_t* bitboard, int ladyPosition)
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
		*bitboard = set_positive_bit_bitboard(*bitboard, bit);

		/**
		 * Vertical
		 */
		bit = currentByte + ladyPositionInByte;
		*bitboard = set_positive_bit_bitboard(*bitboard, bit);

		/**
		 * Diagonal
		 */
		int tmp = (currentByte/BOARD_SIZE) - ladyByte;
		bit = currentByte + ladyPositionInByte + tmp;

		if(bit < BITBOARD_SIZE && bit >= 0)
		{
			*bitboard = set_positive_bit_bitboard(*bitboard, bit);
		}

		bit = currentByte + ladyPositionInByte - tmp;

		if(bit < BITBOARD_SIZE && bit >= 0)
		{
			*bitboard = set_positive_bit_bitboard(*bitboard, bit);
		}
		//printf("%d - %d = %d\t\tbit = %d\n", currentByte/BOARD_SIZE, ladyByte, tmp, bit);
	}
}