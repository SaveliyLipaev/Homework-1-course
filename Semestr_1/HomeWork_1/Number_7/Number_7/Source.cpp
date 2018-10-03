#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

bool prostoe(int number_2);
int main() {
	int number;
	scanf("%d", &number);
	if (number >= 2)
	{
		printf("2 ");
		for (int i = 3; i <= number; i += 2)
		{
			if (prostoe(i))
			{
				printf("%d ", i);
			}
		}
	}
	else printf("UUUps...there are no prime numbers less than or equal to the entered number\n");
	return 0;
}

bool prostoe(int number_2) {
	for (int j = 2; j <= sqrt(number_2); ++j)
	{
		if (number_2 % j == 0)
		{
			return false;
		}
	}
	return true;
}