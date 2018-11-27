#include <stdio.h>
#include <stdlib.h>
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

/* --- GLOBAL FUNCTION DEFINITION --- */
int main(int argc, char* argv[])
{
	/* ------------ EX1 ------------ */
	int a, b;

	printf("enter two numbers please :\n");
	scanf("%d", &a);
	scanf("%d", &b);

	int res = power(a, b);
	printf("%d^%d = %d\n", a, b, res);

	res = recPower(a, b);
	printf("%d^%d = %d\n", a, b, res);

	res = recOptiPower(a, b);
	printf("%d^%d = %d\n", a, b, res);

	/* ------------ EX2 ------------ */
	printf("\nhello my name is henry pot de beurre\nlol\n>.>\n\n");
	wCount("hello my name is henry pot de beurre\nlol\n>.>\n");
	conversion("henrypotdebeurre");
	conversion("512");

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
	if(n == 1)
	{
		return a;
	}else{
		return (a*recPower(a, n-1));
	}
}

int recOptiPower(int a, int n)
{
	if(n == 1)
	{
		return a;
	}else{
		if(n%2 == 0)
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

	printf("we have :\n- %d characters\n- %d words\n- %d lines\n\n", i, word, line);
}

/* ------------ EX3 ------------ */
void conversion(char* string)
{
	int nb, nb10;
	char* newstring;

	if(string[i] > 'a' || string[i] < 'z')
		{
			printf("alphabetical string : %s\n", string);
			base26to10();
			/* printf("%d ", string[i] - 97); */
		}else if(string[i] > '0' || string[i] < '9')
		{
			nb = strtol(string, &newstring, 10);
			printf("numerical string : %d\n", num);
			nb10 = base10to26(nb);
			printf("(%d)_26 == (%d)_10\n", nb, nb10);
		}else
		{
			printf("wrong string you dummie\n");
			return;
		}
	printf("\n");
}

int base26to10()
{
	int i, calc;
	/* abc = a x 26^2 + b x 26^1 + c x 26^0 = 28, avec a = 0, b = 1, c = 2 ... */
	for(i = 0; string[i] != '\0'; i++)
	{
		calc = string[i] * recPower(26, i);
		/* return base26to10();*/
	}
}

int base10to26(int num)
{
	/* tables de conversion comme en architecture ... */
}

/* ------------ EX4 ------------ */
