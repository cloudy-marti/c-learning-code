#include <stdio.h>
#include <stdlib.h>

#include "headers/stack.h"

int main(int argc, char* argv[])
{
	int i;

	if (argc != 2)
	{
		fprintf(stderr, "Nope, I need one positive integer in argument to work properly.\n");
		return 0;
	}

	int size = atoi(argv[1]);

	stack_adr(size, &i, &i);

	int* buffer = (int*)malloc(sizeof(int)*size);

	permutations(buffer, 1, size);

	return 0;
}