#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int binPow(int a, int n);
int linearPow(int a, int n);
bool test(int(*ptrFunc)(int, int));

int main()
{
	if (test(binPow))
	{
		printf("The exponentiation for log(n) was successful!\n");
	}
	else
	{
		printf("The exponentiation for log(n) was failed!\n");
	}
	if (test(linearPow))
	{
		printf("The exponentiation in linear time has been successful!\n");
	}
	else
	{
		printf("The exponentiation in linear time has been failed!\n");
	}
	return 0;
}

bool test(int(*ptrFunc)(int, int))
{
	return ptrFunc(2, 8) == 256 && ptrFunc(5, 12) == 244140625 && ptrFunc(10, 3) == 1000;
}

int binPow(int a, int n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n % 2 == 1)
	{
		return binPow(a, n - 1) * a;
	}
	else
	{
		int b = binPow(a, n / 2);
		return b * b;
	}
}

int linearPow(int a, int n)
{
	int b = 1;
	for (int i = 0; i < n; ++i)
	{
		b *= a;
	}
	return b;
}