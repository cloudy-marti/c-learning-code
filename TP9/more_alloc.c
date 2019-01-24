#include <stdio.h>
#include <stdlib.h>

void print_info_zone(void* adr)
{
	size_t* info_adr = (size_t*)adr;

	printf("Zone a l'adresse : %p\n", adr);
	
	printf("%lu \n", info_adr[-1]);
	printf("%lu \n", info_adr[-2]);
}