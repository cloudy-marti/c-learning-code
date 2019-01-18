#include <stdio.h>
#include <stdlib.h>

#include "headers/firsts_steps.h"

int* initialize_integer_array(int size)
{
	int* array = (int*)malloc(sizeof(int)*size);

	return array;
}

void fill_array(int* array, int size)
{
	int i;

	for(i = 0; i < size; i++)
		array[i] = i+1;
}

void print_array(int* array, int size)
{
	int i;

	for(i = 0; i < size; i++)
		printf("%d ", array[i]);

	printf("\n");
}