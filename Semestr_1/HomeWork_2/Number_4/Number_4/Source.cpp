#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>

int sortingForAssignment(int *mas, int length);
void printMas(int *mas, int length);
bool test(void);

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

	printf("\nArray after processing:\n");
	printMas(mas, length);

	if (test())
	{
		printf("\nThe test was successful\n");
	}
	else
	{
		printf("\nThe test was failed\n");
	}

	delete[] mas;
	return 0;
}

int sortingForAssignment(int *mas, int length)
{
	int firstVariable = mas[0]; 
	int helpVariable = 1;

	for (int i = 1; i < length; ++i)
	{
		if (mas[i] < firstVariable)
		{
			const int buffer = mas[i];
			mas[i] = mas[i - helpVariable];
			mas[i - helpVariable] = buffer;
		}
		else
		{
			++helpVariable;
		}
	}
	return helpVariable;
}

void printMas(int *mas, int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", mas[i]);
	}
	printf("\n");
}

bool test(void)
{
	int array1[6]{ 6, 7, -5, 0, 3, 8 };
	int array2[8]{ 2, 3, 4, 5, 6, 7, -1, 8 };
	return sortingForAssignment(array1, 6) == 3 && sortingForAssignment(array2, 8) == 7;
}