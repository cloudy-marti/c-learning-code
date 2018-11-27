#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/* --- FUNCTION DECLARATIONS --- */

/* ------------ EX1 ------------ */
int power(int a, int n);
int recPower(int a, int n);
int recOptiPower(int a, int n);

/* ------------ EX2 ------------ */
void wCount(char* string);

/* ------------ EX3 ------------ */
void conversion(char* string);
int checkstring(char* string);

/* -- GLOBAL FUNCTION DEFINITION -- */
int main(int argc, char* argv[])
{
	/* ------------ EX1 ------------ */
	int a, b, res;

	printf("enter two numbers please :\n");
	scanf("%d", &a);
	scanf("%d", &b);

	while(b <= 0)
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
	char* string;

	printf("\nLorem ipsum dolor sit amet, consectetur adipiscing elit,\nsed do eiusmod tempor incididunt ut labore\net dolore magna aliqua\n\n");
	wCount("Lorem ipsum dolor sit amet, consectetur adipiscing elit,\nsed do eiusmod tempor incididunt ut labore\net dolore magna aliqua");

	/* ------------ EX3 ------------ */
	printf("enter a string without spaces please ...\n");
	scanf("%s", string);
	conversion(string);
	// conversion("512");

	return EXIT_SUCCESS;
}

/* --- LOCAL FUNCTION DEFINITIONS --- */

/* ------------ EX1 ------------ */
int power(int a, int n)
{
	int i;
	int res = 1;

	if(n <= 0)
	{
		res = -1;
	}else
	{
		for(i = 0; i < n; i++)
		{
			res *= a;
		}
	}
	return res;
}

int recPower(int a, int n)
{
	if(n <= 0)
	{
		return -1;
	}else if(n == 1){
		return a;
	}else{
		return (a*recPower(a, n-1));
	}
}

int recOptiPower(int a, int n)
{
	if(n <= 0)
	{
		return -1;
	}else if(n == 1){
		return a;
	}else{
		if(a%2 == 0)
		{
			int tmp = recPower(a, n/2);
			return (a*tmp);
		}else{
			return (a*recPower(a, n-1));
		}
	}
}

/* ------------ EX2 ------------ */
void wCount(char* string)
{
	int i, word, line;
	i = word = line = 0;

	for(i = 0; string[i] != '\0'; i++)
	{
		if(string[i] == ' ')
		{
			word++;
		}else if(string[i] == '\n'){
			word++;
			line++;
		}
	}

	printf("in the text above we have :\n- %d characters\n- %d words\n- %d lines\n\n", i, word, line + 1);
}

/* ------------ EX3 ------------ */

int checkstring(char* string)
{
	int i = 0;

	if(string[i] > 'a' || string[i] < 'z')
	{
		return 1;
	}else if(string[i] >= '0' || string[i] <= '9')
	{
		return 0;
	}else
		return -1;
}

void conversion(char* string)
{
	int i, nb, base;

	if(checkstring(string) == 0)
	{
		base = 26;

		int result10;
		int lenght = strlen(string);
		nb = result10 = 0;

		for(i = lenght - 1; i >= 0; i--)
		{
			nb = (string[i] - 97);

			if(nb >= base)
			{
				printf("invalid string ...\n");
				return;
			}else if(i == lenght - 1)
			{
				result10 = nb;
			}else{
				result10 += nb * recOptiPower(26, i);
			}
		}

		printf("result = %d\n", result10);

	}else if(checkstring(string) == 1)
	{
		base = 10;

		nb = atoi(string);
		char* result26 = "";
		char numbs[27] = "abcdefghijklmnopqrstuvwxyz";

		while(nb > 0)
		{
			result26 += numbs[nb%base];
			nb /= base;
		}

		printf("result = %d\n", result26);

	}else{
		printf("wrong string ...\n");
	}
}

/* ------------ EX4 ------------ */
