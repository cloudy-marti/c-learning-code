#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "headers/exo0.h"
#include "headers/exo1.h"

int* fill_array(void)
{
    int *array;
    int nb, size, i;

    printf("Please enter the size of your array ...\n");
    scanf("%d", &size);

    array = allocate_integer_array(size);

    printf("Now enter some numbers ... \n");

    for(i = 0; i < size; i++)
    {
    	scanf("%d", &nb);
    	array[i] = nb;
    }

    array[size] = -1;

    return array;
}

int* random_array(int size, int max_entry)
{
	int i, nb;

	int* randArray;
	randArray = allocate_integer_array(size);

	srand(time(NULL));

	for(i = 0; i < size; i++)
	{
		nb = rand()%max_entry;
		randArray[i] = nb;
	}

	randArray[size] = -1;

	return randArray;
}

int* concat_array(int* first, int* second)
{
	int i, firstSize, secondSize, totalSize;
	int* newArray;

	firstSize = array_size(first);
	secondSize = array_size(second);

	totalSize = (firstSize + secondSize);

	newArray = allocate_integer_array(totalSize);

	for(i = 0; i <= totalSize; i++)
	{
		if(i < firstSize)
		{
			newArray[i] = first[i];
		}else
		{
			newArray[i] = second[i-firstSize];
		}
	}

	newArray[totalSize] = -1;

	return newArray;
}