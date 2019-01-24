#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/alloc_arg.h"
#include "headers/more_alloc.h"

int get_size(char* argv)
{
	int counter = 0;

	do counter++;
	while(argv[counter] != '\0');

	return counter+1;
}

char** initialize_arg_array(int argc, char** argv)
{
	char** array = (char**)malloc(sizeof(char*)*argc);

	int i, size;

	for(i = 0; i < argc; ++i)
	{
		size = get_size(argv[i]);
		array[i] = (char*)malloc((sizeof(char)*size));
	}

	return array;
}

void fill_arg_array(int argc, char** argv, char** array)
{
	int i;

	for(i = 0; i < argc; ++i)
		strcpy(array[i], argv[i]);
}

void print_arg_array(int argc, char** array)
{
	int i;

	for(i = 0; i < argc; i++)
		printf("arg[%d] : %s\n", i, array[i]);
}

void free_arg_array(int argc, char** array)
{
	int i;

	for(i = 0; i < argc; ++i)
		free(array[i]);

	free(array);
}