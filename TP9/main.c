#include <stdio.h>
#include <stdlib.h>

#include "headers/firsts_steps.h"
#include "headers/alloc_2D.h"
#include "headers/alloc_arg.h"

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		printf("too few arguments ... please type your desired size\n");
		return -1;
	}

	printf("\n---------------------- Exo1 ----------------------\n");

	int size = atoi(argv[1]);

	int* array = initialize_integer_array(size);

	fill_array(array, size);
	print_array(array, size);

	free(array);

	printf("\n---------------------- Exo2 ----------------------\n");

	int x = 18;
	int y = 12;

	printf("please type two numbers ...\n");
	scanf("%d", &x);
	scanf("%d", &y);
	putchar('\n');

	char** stringArr = initialize_2D_array(x, y);

	fill_2D_array(stringArr, x, y);
	print_2D_array(stringArr, x, y);

	free_2D_array(stringArr, x, y);

	printf("\n---------------------- Exo3 ----------------------\n");

	char** argArray = initialize_arg_array(argc, argv);
	fill_arg_array(argc, argv, argArray);
	print_arg_array(argc, argArray);
	free_arg_array(argc, argArray);

	return 0;
}