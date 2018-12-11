#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/exo1.h"
#include "headers/exo3.h"

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