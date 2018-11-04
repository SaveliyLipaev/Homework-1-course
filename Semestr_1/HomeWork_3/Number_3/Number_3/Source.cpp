#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int &a, int &b);
void siftingDown(int *mas, int root, const int border);
void heapSort(int *mas, const int length);
int mostCommonElementInSortArray(int *mas, const int length);
int mostCommonElement(int *mas, const int length);
bool test(void);

int main()
{
	if (test())
	{
		printf("Test completed\n");
	}
	else
	{
		printf("Test failed");
	}

	return 0;
}

bool test(void)
{
	int array1[11]{ 0, 3, -2, 12, 43, 3, -3, -1, 43, -2, 3 };
	int array2[11]{ -1, -1, -1, -1, -1, 3, -1, -1, 3, 3, 3 };
	int array3[11]{ -11, -13, 0, -13, -1535, 344, 0, -321, 0, 312341, 342424 };

	return mostCommonElement(array1, 11) == 3 && mostCommonElement(array2, 11) == -1 && mostCommonElement(array3, 11) == 0;
}

int mostCommonElement(int *mas, const int length)
{
	heapSort(mas, length);
	return mostCommonElementInSortArray(mas, length);
}

int mostCommonElementInSortArray(int *mas, const int length)
{
	int amount = 1;
	int maxAmount = 0;
	int element = mas[0];

	for (int i = 0; i < length - 1; ++i)
	{
		if (mas[i] == mas[i + 1])
		{
			++amount;
		}
		else
		{
			if (amount > maxAmount)
			{
				maxAmount = amount;
				element = mas[i];
			}
			amount = 1;
		}
	}

	if (amount > maxAmount)
	{
		maxAmount = amount;
		element = mas[length - 1];
	}

	return element;
}

void swap(int &a, int &b)
{
	const int c = a;
	a = b;
	b = c;
}

void siftingDown(int *mas, int root, const int border)
{
	int maxChild = 0;
	bool flagPyramidShaped = false;

	while ((root * 2 + 1 <= border) && !flagPyramidShaped)
	{
		if (root * 2 + 1 == border)
		{
			maxChild = root * 2 + 1;
		}
		else
		{
			if (mas[root * 2 + 1] > mas[root * 2 + 2])
			{
				maxChild = root * 2 + 1;
			}
			else
			{
				maxChild = root * 2 + 2;
			}
		}

		if (mas[root] < mas[maxChild])
		{
			swap(mas[maxChild], mas[root]);
			root = maxChild;
		}
		else
		{
			flagPyramidShaped = true;
		}
	}
}

void heapSort(int *mas, const int length)
{
	for (int i = (length / 2) - 1; i >= 0; --i)
	{
		siftingDown(mas, i, length - 1);
	}

	for (int i = length - 1; i >= 1; --i)
	{
		swap(mas[0], mas[i]);
		siftingDown(mas, 0, i - 1);
	}
}