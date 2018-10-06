#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>

bool test(void);
void swap(int& a, int& b);
void sorting(int* mas, int left, int right);
void sortingInsert(int* mas, int left, int right);
void qusort(int* mas, int left, int right);
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

bool test(void)
{
	int array1[7] = { 5, 1, 8, 0, 5, 3, 3 };
	int array2[13] = { 8, -3, 5, 0, -5, -1, -4, -3, 8, 100, 43, -32, 5 };
	int array3[30];

	for (int i = 0; i < 30; ++i)
	{
		array3[i] = rand() % 500;
	}

	sorting(array1, 0, 6);
	sorting(array2, 3, 12);
	sorting(array3, 0, 29);

	for (int i = 0; i < 6; ++i)
	{
		if (array1[i] > array1[i + 1])
		{
			return false;
		}
	}

	for (int i = 3; i < 12; ++i)
	{
		if (array2[i] > array2[i + 1])
		{
			return false;
		}
	}

	for (int i = 0; i < 29; ++i)
	{
		if (array3[i] > array3[i + 1])
		{
			return false;
		}
	}
	return true;
}

void sorting(int* mas, int left, int right)
{
	if (right - left <= 8)
	{
		sortingInsert(mas, left, right);
	}
	else
	{
		qusort(mas, left, right);
	}
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