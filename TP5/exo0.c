#include <stdio.h>
#include <stdlib.h>

int* allocate_integer_array(int size)
{
    int* new_tab;
    new_tab = (int*)malloc((size+1)*sizeof(int));

    if (new_tab == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        return NULL;
    }

    return new_tab;
}

void free_integer_array(int* tab)
{
    free(tab);
}

void bubbleSort(int* tab, int size)
{
    int i, j, tmp, oriSize;
    oriSize = size;

    for(j = 1; j < oriSize; j++)
    {
        for(i = 0; i < size-1; i++)
        {
            if(tab[i] > tab[i+1])
            {
                tmp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = tmp;
            }
        }
        size--;
    }
}