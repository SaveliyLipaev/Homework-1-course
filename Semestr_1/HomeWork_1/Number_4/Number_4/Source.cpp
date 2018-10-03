#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int sums[28]{}, happy_ticket = 0;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < 10; ++k)
			{
				++sums[i + j + k];
			}
		}
	}
	for (int i = 0; i < 28; ++i)
	{
		happy_ticket += sums[i] * sums[i];
	}
	printf("%d\n", happy_ticket);
	return 0;
}