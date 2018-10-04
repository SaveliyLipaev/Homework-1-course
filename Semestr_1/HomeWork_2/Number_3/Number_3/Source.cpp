#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>

void bubble(int *mas, int length);
void sortingCounting(int *mas, int length);
bool test(void(*ptrFunction)(int*, int));

int main()
{
	if (test(bubble))
	{
		printf("The test using bubble sorting was successful!\n\n");
	}
	else
	{
		printf("The test using bubble sorting was failed!\n\n");
	}

	if (test(sortingCounting))
	{
		printf("The test using sorting by counting was successful!\n\n");
	}
	else
	{
		printf("The test using sorting by counting was failed!\n\n");
	}
	return 0;
}

void bubble(int *mas, int length)
{
	for (int i = 0; i < length; ++i)
	{
		for (int j = length - 1; j > i; --j)
		{
			if (mas[j] < mas[j - 1])
			{
				const int buffer = mas[j];
				mas[j] = mas[j - 1];
				mas[j - 1] = buffer;
			}
		}
	}
}

void sortingCounting(int *mas, int length)
{
	int max = 0;
	int min = 0;

	for (int i = 0; i < length; ++i)
	{
		if (mas[i] > max)
		{
			max = mas[i];
		}
		if (mas[i] < min)
		{
			min = mas[i];
		}
	}

	int *helpMasPos = new int[max + abs(min) + 1]{};

	for (int i = 0; i < length; ++i)
	{
		++helpMasPos[mas[i] + abs(min)];
	}

	int indexInMainArrayToFill = 0;

	for (int i = 0; i <= max + abs(min); ++i)
	{
		for (int j = 0; j < helpMasPos[i]; ++j)
		{
			mas[indexInMainArrayToFill] = i - abs(min);
			++indexInMainArrayToFill;
		}
	}

	delete[] helpMasPos;
}

bool test(void(*ptrFunction)(int*, int))
{
	int array1[9] = { 5, 6, 3, 1, 8, 0, 5, 3, 3 };
	int array2[9] = { 8, -3, 5, 0, -5, -1, -4, -3, 8 };
	ptrFunction(array1, 9);
	ptrFunction(array2, 9);
	for (int i = 0; i < 8; ++i)
	{
		if ((array1[i] > array1[i + 1]) || (array2[i] > array2[i + 1]))
		{
			return false;
		}
	}
	return true;
}