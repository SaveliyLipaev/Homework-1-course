#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctime>
#include <cstdlib>

int main()
{
	srand(time(0));
	int n = 0;
	int k = 0;

	scanf("%d%d", &n, &k);
	int * mas = new int[n];

	for (int i = 0; i < n; ++i)
		mas[i] = (rand() % 1000 + 1) * (rand() % 1000 + 1) * (rand() % 1000 + 1);
	
	for (int i = 0; i < n; ++i)
		printf("%d\n ", mas[i]);

	scanf("%d", &n);
	delete[] mas;
	return 0;
}


