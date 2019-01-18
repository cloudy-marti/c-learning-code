#include <stdio.h>

int power(int a, int n)
{
	int i;
	int res = 1;

	if(n < 0) res = -1;
	else if(n == 0) res = 1;
	else
	{
		for(i = 0; i < n; i++)
			res *= a;
	}
	return res;
}

int recPower(int a, int n)
{
	if(n < 0) return -1;
	else if(n == 0) return 1;
	else if(n == 1) return a;
	else return (a*recPower(a, n-1));
}

int recOptiPower(int a, int n)
{
	if(n < 0) return -1;
	else if(n == 0) return 1;
	else if(n == 1) return a;
	else
	{
		if(n%2 == 0)
		{
			int tmp = recOptiPower(a, n/2);
			return (tmp*tmp);
		}
		else return (a*recOptiPower(a, n-1));
	}
}