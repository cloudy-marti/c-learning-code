#include <stdio.h>
#include <stdlib.h>

#include "headers/syracuse.h"

int main(int argc, char* argv[])
{
	long int number, unsignedNumber;

	printf("\nHello, please enter your number.\n");
	scanf("%li", &number);

	unsignedNumber = (long unsigned int)number;

	printf("\n-------------------- Phase One --------------------\n");
	printf("\nSyracuse Problem :\n");
	print_syracuse(unsignedNumber);

	putchar('\n');

	long unsigned int fly = fly_syracuse(unsignedNumber);
	long unsigned int max = max_syracuse(unsignedNumber);

	printf("fly = %ld\nmax value = %ld\n", fly, max);

	printf("\n-------------------- Phase Two --------------------\n");

	long int* cache = initialize_array(unsignedNumber);
	fill_array(cache, unsignedNumber);

	long int optiFly = opti_fly_syracuse(cache, unsignedNumber);

	printf("\noptimised fly = %li\n\n", optiFly);

	return 0;
}