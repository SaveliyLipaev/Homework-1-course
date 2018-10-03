#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fibonacciRecursion(int n);
int fibonacciIteratively(int n);
bool test(int(*ptrFunction)(int));

int main()
{
	if (test(fibonacciRecursion))
	{
		printf("Calculating the Fibonacci Numbers Using Recursion Successfully\n\n");
	}
	else
	{
		printf("Calculating the Fibonacci Numbers Using Recursion failed\n\n");
	}

	if (test(fibonacciIteratively))
	{
		printf("Calculating the Fibonacci Numbers Using Itteration Successfully\n\n");
	}
	else
	{
		printf("Calculating the Fibonacci Numbers Using Itteration failed\n\n");
	}
	return 0;
}

int fibonacciRecursion(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	if (n <= 0)
	{
		return -1;
	}
	return fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
}

int fibonacciIteratively(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	if (n <= 0)
	{
		return -1;
	}
	int fibonacci1 = 1;
	int fibonacci2 = 1;
	int fibonacci3 = 2;
	for (int i = 0; i < n - 3; ++i)
	{
		fibonacci1 = fibonacci2;
		fibonacci2 = fibonacci3;
		fibonacci3 = fibonacci1 + fibonacci2;
	}
	return fibonacci3;
}

bool test(int(*ptrFunction)(int))
{
	return ptrFunction(1) == 1 && ptrFunction(5) == 5 && ptrFunction(-3) == -1 && ptrFunction(10) == 55;
}