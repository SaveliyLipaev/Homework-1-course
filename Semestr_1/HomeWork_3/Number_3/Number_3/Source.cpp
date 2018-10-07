#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int &a, int &b);
void siftingDown(int *mas, int root, const int border);
void heapSort(int *mas, const int length);

int main()
{
	int mas[8] = { 5,7,3,2,8,1,9,6 };
	
	heapSort(mas, 8);


	for (int i = 0; i < 8; i++)
		printf("%d ", mas[i]);

	int n;
	scanf("%d", &n);
	return 0;
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