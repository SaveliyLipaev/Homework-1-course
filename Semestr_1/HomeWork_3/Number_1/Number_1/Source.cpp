#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printmas(int* m, int length);
void swap(int& a, int& b);
void sortingInsert(int* mas, int left, int right);
void qusort(int* mas, int left, int right);
int partition(int* mas, int left, int right);

int main()
{
	const int n = 7;
	int array[n]{ 3, 5, 4, 9, 7, 2, 1 };
	sortingInsert(array, 0, 6);
	printmas(array, 7);


	int p;
	scanf("%d", &p);
	return 0;
}

void sortingInsert(int* mas, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		for (int j = i; j > 0 && mas[j] < mas[j - 1]; --j)
		{
			swap(mas[j], mas[j - 1]);
		}
	}
}

void printmas(int* m, int length)
{
	for (int i = 0; i < length; i++)
		printf("%d ", m[i]);
	printf("\n");
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
	printmas(mas, 7);
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