#include <stdio.h>
#include <stdlib.h>

#include "headers/syracuse.h"

int main(int argc, char* argv[])
{
	print_syracuse(27);
	int fly = fly_syracuse(27);
	int max = max_syracuse(27);
	printf("fly = %d\nmax value = %d\n", fly, max);

	return 0;
}