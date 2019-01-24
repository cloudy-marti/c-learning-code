#include <stdio.h>
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

int fly_syracuse(long unsigned int nb)
{
	if(nb == 1) return 0;

	if(nb%2 == 0) return 1 + fly_syracuse(nb/2);
	else return 1 + fly_syracuse((3*nb)+1);

	return 0;
}

int max_syracuse(long unsigned int nb)
{
	int index;

	for(index = nb; index != 1; )
	{
		if(nb < index) nb = index;

		if(index%2 == 0) index /= 2;
		else index = (3*index) + 1;
	}

	return nb;
}