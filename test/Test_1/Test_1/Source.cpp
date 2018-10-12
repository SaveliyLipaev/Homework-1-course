#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool test_task_2(void);
void sortingInsert(int* mas, int left, int right);
void swap(int& a, int& b);

int main()
{
	if (test_task_2())
	{
		printf("Succeful!!!Number 2!\n");
	}
	else
	{
		printf("Failed!:((\n");
	}


	//int n;
	//scanf("%d", &n);
	return 0;
}

void FuncFromFirstTask(bool *mas1, int length1, bool *mas2, int length2)
{



}

bool test_task_2(void)
{
	int array1[10] = { 5, 1, 8, 0, 5, 3, 3, 6, 7, 1 };
	int array2[10] = { 8, -3, 5, 0, -5, -1, -4, -3, 8, 100 };

	sortingInsert(array1, 0, 9);
	sortingInsert(array2, 0, 9);

	for (int i = 0; i < 9; ++i)
	{
		if (array1[i] > array1[i + 1])
		{
			return false;
		}
	}

	for (int i = 0; i < 9; ++i)
	{
		if (array2[i] > array2[i + 1])
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