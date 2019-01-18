#include <stdio.h>
#include <stdlib.h>

#include "headers/firsts_steps.h"
#include "headers/alloc_2D.h"

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		printf("too few arguments ...\n");
		return -1;
	}

	int size = atoi(argv[1]);

	int* array = initialize_integer_array(size);

	fill_array(array, size);
	print_array(array, size);

	free(array);

	printf("-------------------------------------\n\n");

	int x = 18;
	int y = 36;

	char** stringArr = initialize_2D_array(x, y);

	printf("---------------\n");

	fill_2D_array(stringArr, x, y);
	print_2D_array(stringArr, x, y);

	return 0;
}