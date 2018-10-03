#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>

int main() {
	int a, b, counter = 0, helper = 1;
	printf("Enter a and b\n");
	scanf("%d%d", &a, &b);
	if (b == 0)
	{
		printf("Error!!!NOT ZERO!!!\n");
		return 0;
	}
	if (a < 0 ^ b < 0)
	{
		helper = -1;
	}
	a = abs(a);
	b = abs(b);
	while (a >= b)
	{
		a -= b;
		++counter;
	}
	printf("Nepolnoe chastnoe = %d\n", counter*helper);
	return 0;
}