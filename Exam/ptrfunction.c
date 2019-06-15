#include <stdio.h>

typedef int (*addfunky)(int, int);

int add(int a, int b)
{
	return a+b;
}

int add2(int a, int b)
{
	return b+a;
}

int addgeneric(int a, int b, addfunky addfunction)
{
	return addfunction(a, b);
}

int main(int argc, char** argv)
{
	int a = 2;
	int b = 6;

	int c = addgeneric(a, b, add);

	printf("%d + %d = %d\n", a, b, c);
}