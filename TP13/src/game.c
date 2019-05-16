#include <MLV/MLV_all.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>

#include "../headers/checkers.h"

int main(int argc, char** argv)
{
	printf("size of unsigned long int = %ld\tsize of int = %ld\n", sizeof(unsigned long int), sizeof(int));

	unsigned long int bitboard;

	printf("input\n");
	scanf("%ld", &bitboard);

	print_bitboard(bitboard);

	return 0;
}
