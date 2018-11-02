#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>

bool test();
bool checkArray(int *mas, const int length);
void swap(int& a, int& b);
void sortingInsert(int* mas, int left, int right);
void qsort(int* mas, int left, int right);
int partition(int* mas, int left, int right);

int main()
{	
	if (test())
	{
		printf("The test using sorting was successful!\n\n");
	}
	else
	{
		printf("The test using sorting was failed!\n\n");
	}
	return 0;
}

bool test()
{
	int array1[7] = { 5, 1, 8, 0, 5, 3, 3 };
	int array2[13] = { 8, -3, 5, 0, -5, -1, -4, -3, 8, 100, 43, -32, 5 };

	return checkArray(array1, 7) && checkArray(array2, 13);
}

bool checkArray(int *mas, const int length)
{
	qsort(mas, 0, length - 1);
	for (int i = 0; i < length - 1; ++i)
	{
		if (mas[i] > mas[i + 1])
		{
			return false;
		}
	}
	return true;
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

void qsort(int* mas, int left, int right)
{
	if (right - left < 10)
	{
		sortingInsert(mas, left, right);
	}
	if (right < left)
	{
		return;
	}
	const int p = partition(mas, left, right);
	qsort(mas, left, p - 1);
	qsort(mas, p + 1, right);
}