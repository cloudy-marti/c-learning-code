#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* tab, int min, int max, int nb)
{
	int mid;

	if(min > max) return -1;

	if(min == max)
	{
		if(tab[min] == nb)
		{
			printf("number %d has been found on index %d.\n", nb, min);
			return nb;
		}
		else
		{
			printf("number %d is not in this array ...\n", nb);
			return -1;
		}
	}

	mid = (min + max) / 2;

	if(tab[mid] < nb) return binarySearch(tab, mid+1, max, nb);
	else return binarySearch(tab, min, mid, nb);
	
	return nb;
}

void printArray(int* array, int size)
{
	int i;

	for(i = 0; i < size; i++)
		printf("%d ", array[i]);

	printf("\n");
}

void fillRandArray(int* array, int size)
{
	int i;

	for(i = 0; i < size; i++)
		array[i] = rand()%50;

	printf("\n");
}