#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>

void swap(int &x1, int &x2);
void sortingForAssignment(int *mas, int length);
void printMas(int *mas, int length);

int main()
{
	int length = 0;
	printf("Enter the length of the array: \n");
	scanf("%d", &length);
	while (length <= 0)
	{
		printf("Input error, please try again\n");
		scanf("%d", &length);
	}

	int *mas = new int[length];

	for (int i = 0; i < length; ++i)
	{
		mas[i] = rand() % 100;
	}

	printf("Array before processing:\n");
	printMas(mas, length);

	sortingForAssignment(mas, length);

	printf("Array after processing:\n");
	printMas(mas, length);

	delete[] mas;
	return 0;
}

void swap(int &x1, int &x2)
{
	int b = x1;
	x1 = x2;
	x2 = b;
}

void sortingForAssignment(int *mas, int length)
{
	int firstVeriable = mas[0], helpVeriable = 1;
	for (int i = 1; i < length; ++i)
	{
		if (mas[i] < firstVeriable)
		{
			swap(mas[i], mas[i - helpVeriable]);
		}
		else
		{
			++helpVeriable;
		}
	}

}

void printMas(int *mas, int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", mas[i]);
	}
	printf("\n");
}
