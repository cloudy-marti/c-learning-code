#include <stdio.h>
#include "headers/exo0.h"

int array_size(int* array)
{
    int i, counter;
    counter = 0;

    for(i = 0; array[i] != -1; i++)
        counter++;

    return counter;
}

void print_array(int* array)
{
    int i, size;
    size = array_size(array);

    for(i = 0; i < size; i++)
        printf("%d ", array[i]);

    printf("\n");
}

int are_arrays_equal(int* first, int* second)
{
    int i;

    for(i = 0; first[i] != -1; i++)
        if(first[i] != second[i]) return 0;

    return 1;
}

int* copy_array(int* array)
{
    int *newArray;

    int i, size;
    size = array_size(array);

    newArray = allocate_integer_array(size);

    for(i = 0; array[i] != -1; i++)
        newArray[i] = array[i];

    newArray[size] = -1;

    return newArray;
}