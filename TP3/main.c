#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "headers/exo1.h"
#include "headers/exo2.h"
#include "headers/exo3.h"
#include "headers/exo4.h"
#include "headers/exo5.h"

/* -- GLOBAL FUNCTION DEFINITION -- */
int main(int argc, char* argv[])
{
	/* ------------ EX1 ------------ */
	int a, b, res;

	printf("enter two numbers please :\n");
	scanf("%d", &a);
	scanf("%d", &b);

	while(b < 0)
	{
		printf("wrong numbers ! Please re-enter two numbers ... \n");
		scanf("%d", &a);
		scanf("%d", &b);
	}

	res = power(a, b);
	printf("normal power function\n%d^%d = %d\n\n", a, b, res);

	res = recPower(a, b);
	printf("recursive power function\n%d^%d = %d\n\n", a, b, res);

	res = recOptiPower(a, b);
	printf("optimised recursive power function\n%d^%d = %d\n", a, b, res);

	/* ------------ EX2 ------------ */
	char string[256];

	printf("\nLorem ipsum dolor sit amet, consectetur adipiscing elit,\nsed do eiusmod tempor incididunt ut labore\net dolore magna aliqua\n\n");
	wCount("Lorem ipsum dolor sit amet, consectetur adipiscing elit,\nsed do eiusmod tempor incididunt ut labore\net dolore magna aliqua");

	/* ------------ EX3 ------------ */
	printf("enter a string without spaces please ...\n");
	scanf("%s", string);
	conversion(string);

	/* ------------ EX4 ------------ */
	int nb, size;
	size = 10;
	int array[size];
	
	printf("The array is the following :\n");

	/*for(i = 0; i < size; i++)
	{
		array[i] = i*3;
		printf("%d ", array[i]);
	}*/

	fillRandArray(array, size);
	printArray(array, size);

	printf("please choose an integer\n");
	scanf("%d", &nb);

	binarySearch(array, 0, size, nb);

	/* ------------ EX4 ------------ */
	srand(time(NULL));

	fillRandArray(array, size);
	printArray(array, size);

	/*for(i = 0; i < size; i++)
	{
		array[i] = rand()%50;
		printf("%d ", array[i]);
	}

	printf("\n");*/

	bubbleSort(array, size);

	printf("final result :\n");
	printArray(array, size);
	/*for(i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n");*/

	return EXIT_SUCCESS;
}