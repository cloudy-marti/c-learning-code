#include <stdio.h>

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