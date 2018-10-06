#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctime>
#include <cstdlib>

int main()
{
	srand(time(0));
	int n = 0;
	int k = 0;
	
	printf("Enter n and k:");
	scanf("%d%d", &n, &k);
	int * mas = new int[n];

	for (int i = 0; i < n; ++i)
	{
		mas[i] = (rand() % 1000 + 1) * (rand() % 1000 + 1) * (rand() % 1000 + 1);
	}


	scanf("%d", &n);
	delete[] mas;
	return 0;
}

void swap(int& a, int& b)
{
	const int c = a;
	a = b;
	b = c;
}

int partition(int* mas, int left, int right)
{
	const int pivot = mas[right];
	int i = left;

	for (int j = left; j < right; j++)
	{
		if (mas[j] <= pivot)
		{
			swap(mas[i], mas[j]);
			i++;
		}
	}
	swap(mas[i], mas[right]);
	return i;
}

void qusort(int* mas, int left, int right)
{
	if (right < left)
	{
		return;
	}
	const int p = partition(mas, left, right);
	qusort(mas, left, p - 1);
	qusort(mas, p + 1, right);
}
