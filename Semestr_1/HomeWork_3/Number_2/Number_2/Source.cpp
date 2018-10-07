#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctime>
#include <cstdlib>

void swap(int& a, int& b);
int partition(int* mas, int left, int right);
void qusort(int* mas, int left, int right);
bool binSearch(int* mas, int left, int right, int searchVeriable);

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

	qusort(mas, 0, n - 1);
	
	for (int i = 0; i < k; ++i)
	{
		const unsigned int randomVeriable = (rand() % 1000 + 1) * (rand() % 1000 + 1) * (rand() % 1000 + 1);
		if (binSearch(mas, 0, n - 1, randomVeriable))
		{
			printf("%d\n", randomVeriable);
		}
	}

	scanf("%d", &n);
	delete[] mas;
	return 0;
}

bool binSearch(int* mas, int left, int right, int searchVeriable)
{
	const int average = (right + left) / 2;

	if (left >= right)
	{
		if (mas[left] == searchVeriable)
		{
			return true;
		}
		return false;
	}

	if (mas[average] == searchVeriable)
	{
		return true;
	}

	if (mas[average] > searchVeriable)
	{
		return binSearch(mas, left, average - 1 , searchVeriable);
	}

	if (mas[average] < searchVeriable)
	{
		return binSearch(mas, average + 1 , right, searchVeriable);
	}
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
