#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <fstream>


void brushSort(int *array, int length);
void swap(int &a, int &b);
bool test_2();

int main()
{
	if (test_2)
	{
		printf("brush sort was succeful!!\n");
	}
	else
	{
		printf("failed!(\n");
	}

	char buffer = 0;
	bool flag = false;

	printf("\nComments starting with; and ends with the end of the line:\n\n");

	FILE * file = fopen("FileTest.txt", "r");
	while (fscanf(file, "%c", &buffer) != EOF)
	{
		if (buffer == ';')
		{
			flag = true;
		}
		if (flag)
		{
			printf("%c", buffer);
		}
		if (buffer == '\n')
		{
			flag = false;
		}
	}

	fclose(file);
	return 0;
}

void brushSort(int *array, int length)
{
	int helper;
	int step = length; 
	int counter = 0;
	while (length > 1)
	{
		step /= 1.2f; 
			
		if (step < 1)
		{
			step = 1;
		}
		helper = 0; 
		for (int i = 0; i + step < length; ++i)
		{
			if (array[i] > array[i + step])
			{
				swap(array[i], array[i + step]);
				helper = i;
			}
			++counter;
		}
		if (step == 1) 
		{
			length = helper + 1;
		}
	}
}

void swap(int &a, int &b)
{
	const int c = a;
	a = b;
	b = c;
}

bool test_2(void)
{
	int array1[10] = { 5, 1, 8, 0, 5, 3, 3 , 0, 0, 1 };
	int array2[10] = { 8, -3, 5, 0, -5, -1, -4, -3, 8, 100 };

	brushSort(array1, 10);
	brushSort(array2, 10);

	for (int i = 0; i < 10; ++i)
	{
		if (array1[i] > array1[i + 1] || array2[i] > array2[i + 1])
		{
			return false;
		}
	}
	return true;
}
