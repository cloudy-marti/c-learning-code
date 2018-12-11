#include <stdio.h>

int binarySearch(int* tab, int min, int max, int nb)
{
	int i, mid;

	if(min == max)
	{
		if(tab[min] == nb)
		{
			printf("number %d has been found on index %d.\n", nb, min);
			return nb;
		}else{
			printf("number %d is not in this array ...\n", nb);
			return -1;x
		}
	}

	mid = (min + max) / 2;

	for(i = min; i <= max; i++)
	{
		if(tab[mid] < nb)
		{
			return binarySearch(tab, mid+1, max, nb);
		}else
		{
			return binarySearch(tab, min, mid, nb);
		}
	}
}