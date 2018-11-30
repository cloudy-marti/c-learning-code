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
int checkstring(char* string);
void to10(char* string);
void to26(char* string);
void mirror(char* string);
void conversion(char* string);

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
	char* string;

	printf("\nLorem ipsum dolor sit amet, consectetur adipiscing elit,\nsed do eiusmod tempor incididunt ut labore\net dolore magna aliqua\n\n");
	wCount("Lorem ipsum dolor sit amet, consectetur adipiscing elit,\nsed do eiusmod tempor incididunt ut labore\net dolore magna aliqua");

	/* ------------ EX3 ------------ */
	printf("enter a string without spaces please ...\n");
	scanf("%s", string);
	conversion(string);

	/* ------------ EX4 ------------ */

	return EXIT_SUCCESS;
}

/* --- LOCAL FUNCTION DEFINITIONS --- */

/* ------------ EX1 ------------ */
int power(int a, int n)
{
	int i;
	int res = 1;

	if(n < 0)
	{
		res = -1;
	}else if(n == 0){
		res = 1;
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
	if(n < 0)
	{
		return -1;
	}else if(n == 0){
		return 1;
	}else if(n == 1){
		return a;
	}else{
		return (a*recPower(a, n-1));
	}
}

int recOptiPower(int a, int n)
{
	if(n < 0)
	{
		return -1;
	}else if(n == 0){
		return 1;
	}else if(n == 1){
		return a;
	}else{
		if(n%2 == 0)
		{
			int tmp = recOptiPower(a, n/2);
			return (tmp*tmp);
		}else{
			return (a*recOptiPower(a, n-1));
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
	int i, tmp;

	if(string[0] >= 'a' && string[0] <= 'z')
	{
		tmp = 1;
	}else if(string[0] >= '0' && string[0] <= '9')
	{
		tmp = 0;
	}else{
		tmp = -1;
	}

	for(i = 0; i != '\0'; i++)
	{
		if(tmp == 1)
		{
			if(string[i] < 'a' || string[i] > 'z')
			{
				printf("%c is not a letter\n", string[i]);
				return -1;
			}
		}else if(tmp == 0)
		{
			if(string[i] < '0' || string[i] > '9')
			{
				printf("%c is not a number\n", string[i]);
				return -1;
			}
		}else
			return -1;	
	}

	return tmp;
}

void to10(char* string)
{
	int i, nb, lenght, pow, res;
	res = 0;

	lenght = strlen(string);

	for(i = 0; i < lenght; i++)
	{
		nb = (string[i] - 97);
		pow = lenght - i - 1;

		printf("%c = %d\n", string[i], nb);

		if(nb >= 26)
		{
			printf("invalid string ...\n");
			return;

		}else{
			printf("26^%d = %d\n", pow, recOptiPower(26, pow));
			res += nb * recOptiPower(26, pow);
		}
		printf("result = %d\n", res);
	}

	printf("final result = %d\n", res);

	return;
}

void to26(char* string)
{
	int i = 0;
	int nb = atoi(string);
	char res[256];

	while(nb > 0)
	{
		res[i] += 'a'+nb%26;
		nb /= 26;
		i++;
	}

	res[i] = '\0';

	mirror(res);
}

void mirror(char* string)
{
	int i, lenght;
	lenght = strlen(string) - 1;

	for(i = lenght; i >= 0; i--)
	{
		printf("%c", string[i]);
	}
	printf("\n");
}

void conversion(char* string)
{
	int tmp;
	tmp = checkstring(string);

	if(tmp == 1)
	{
		printf("entering base 26 to 10\n");
		to10(string);

	}else if(tmp == 0)
	{
		printf("entering base 10 to 26\n");
		to26(string);

	}else{
		printf("wrong string you dummie ...\n");
	}
}

/* ------------ EX4 ------------ */

