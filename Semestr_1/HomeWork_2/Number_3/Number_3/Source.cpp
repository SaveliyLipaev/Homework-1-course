#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int &x1, int &x2);
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

void swap(int &x1, int &x2)
{
	int b = x1;
	x1 = x2;
	x2 = b;
}

void bubble(int *mas, int length)
{
	for (int i = 0; i < length; ++i)
	{
		for (int j = length - 1; j > i; --j)
		{
			if (mas[j] < mas[j - 1])
			{
				swap(mas[j], mas[j - 1]);
			}
		}
	}
}

void sortingCounting(int *mas, int length)
{
	int max = 0, helpVariable = 0, min = 0;
	for (int i = 0; i < length; ++i)
	{
		if (mas[i] > max)
		{
			max = mas[i];
		}
	}
	int *helpMasPos = new int[max + 1];
	for (int i = 0; i <= max; ++i)
	{
		helpMasPos[i] = 0;
	}

	for (int i = 0; i < length; ++i)
	{
		++helpMasPos[mas[i]];
	}

	for (int i = 0; i <= max; ++i)
	{
		for (int j = 0; j < helpMasPos[i]; ++j)
		{
			mas[helpVariable] = i;
			++helpVariable;
		}
	}
	delete[] helpMasPos;
}

bool test(void(*ptrFunction)(int*, int))
{
	int aray[9] = { 5,6,3,1,8,9,5,3,3 };
	ptrFunction(aray, 9);
	for (int i = 0; i < 8; ++i)
	{
		if (aray[i] > aray[i + 1])
			return 0;
	}
	return 1;
}