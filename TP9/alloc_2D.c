#include <stdio.h>
#include <stdlib.h>

#include "headers/alloc_2D.h"

char** initialize_2D_array(int sizeX, int sizeY)
{
	char** array = (char**)malloc(sizeof(char*)*sizeY); 

	int i;

	for(i = 0; i < sizeY; ++i)
		array[i] = (char*)malloc((sizeof(char)*sizeX));

	return array;
}

void fill_2D_array(char** array, int sizeX, int sizeY)
{
	int i, j;

	int counter = 0;

	for(i = 0; i < sizeY; ++i)
		for(j = 0; j < sizeX; ++j)
		{
			if(j == 0) counter = i;
			if(counter >= 26) counter -= 26;

			array[i][j] = 'a' + counter;
			counter++;
		}
}

void print_2D_array(char** array, int sizeX, int sizeY)
{
	int i, j;

	for(i = 0; i < sizeY; ++i)
	{
		for(j = 0; j < sizeX; ++j)
			printf("%c ", array[i][j]);

		printf("\n");
	}

}


void free_2D_array(char** array, int sizeX, int sizeY)
{
	int i;
	
	for(i = 0; i < sizeY; ++i)
		free(array[i]);

	free(array);
	
}