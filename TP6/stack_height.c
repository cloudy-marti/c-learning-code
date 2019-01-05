#include <stdio.h>
#include <stdlib.h>

void make_space(int n);
int stack_adr(int n, int* height, int* start_adr);
void permutations(int buffer[], int current, int max);
void print_array(int buffer[], int size);

int main(int argc, char* argv[])
{
	int i;

	if (argc != 2)
	{
		fprintf(stderr, "Nope, I need one positive integer in argument to work properly.\n");
	}

	stack_adr(atoi(argv[1]), &i, &i);

	int buffer[6] = {0};

	permutations(buffer, 1, 6);

	return 0;
}

/* Display indentation following the depth of recursion */
void make_space(int n)
{
	int i;

	for (i=0 ; i<n ; i++)
	{
		printf("  ");
	}
}

/* Recursive function displaying the height of the execution stack */
int stack_adr(int n, int* height, int* start_adr)
{
	int p=n;

	if (n >= 0){
		make_space(n);
		printf("Recursive climbing call : %d\n", p);
		make_space(n);
		printf("Adr pointer : %p and Adr local variable : %p\n", height, &p);
		make_space(n);
		printf("Stack jump : %ld\n", height-&p);
		make_space(n);
		printf("Stack total height : %ld\n\n", start_adr-&p);

		stack_adr(n-1, &p, start_adr);

		make_space(n);
		printf("Recursive descending call : %d\n", p);
		make_space(n);
		printf("Stack total height : %ld\n\n", start_adr-&p);
	}else
	{
		printf("LAST RECURSION\n\n");
	}
	return p;
}

void permutations(int buffer[], int current, int max)
{
	int i;

	if(current != 1)
	{
		for(i = 1; i < current; i++)
		{
			putchar('\t');
		}
		printf("--> ");
	}
	print_array(buffer, max);

	if(current > max) return;
	else
	{
		for(i = 0; i < max; i++)
		{
			if(buffer[i] == 0)
			{
				buffer[i] = current;
				permutations(buffer, current+1, max);
				buffer[i] = 0;
			}
		}
	}
}

void print_array(int buffer[], int size)
{
	int i;

	printf("[");
	for(i = 0; i < size; i++)
	{
		if(i != 0)
		{
			printf(", ");
		}
		printf("%d", buffer[i]);
	}
	printf("]\n");
}