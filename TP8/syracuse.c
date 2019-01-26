#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "headers/syracuse.h"

void print_syracuse(long unsigned int nb)
{
	printf("%lu ", nb);

	if(nb == 1)
	{
		printf("\n");
		return;
	}

	if(nb%2 == 0) print_syracuse(nb/2);
	else print_syracuse((3*nb)+1);
}

long unsigned int fly_syracuse(long unsigned int nb)
{
	if(nb == 1) return 0;

	if(nb%2 == 0) return 1 + fly_syracuse(nb/2);
	else return 1 + fly_syracuse((3*nb)+1);

	return 0;
}

long unsigned int max_syracuse(long unsigned int nb)
{
	long unsigned int index;

	for(index = nb; index != 1; )
	{
		if(nb < index) nb = index;

		if(index%2 == 0) index /= 2;
		else index = (3*index) + 1;
	}

	return nb;
}

long int opti_fly_syracuse(long int* cache, long int nb)
{
	if(nb == 1) return 0;
	if(cache[nb] != -1) return cache[nb];
	else
	{
		cache[nb] = fly_syracuse(nb);
		opti_fly_syracuse(cache, nb-1);
		return cache[nb];
	}

	return 0;
}

long int* initialize_array(long int size)
{
	return (long int*)malloc(sizeof(long int)*(size+1));
}

void fill_array(long int* array, long int size)
{
	int i;
	for(i = 0; i <= size; ++i)
		array[i] = -1;
}