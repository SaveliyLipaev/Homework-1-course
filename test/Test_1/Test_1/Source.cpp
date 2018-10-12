#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool test_task_2(void);
void sortingInsert(int* mas, int left, int right);
void swap(int& a, int& b);
bool test_task_1(void);
int FuncFromFirstTask(bool *mas1, int length1, bool *mas2, int length2);
int linearPow(int a, int n);

int main()
{
	if (test_task_1())
	{
		printf("Test 1 task passed successfully!!!\n");
	}
	else
	{
		printf("Failed!:((\n");
	}

	if (test_task_2())
	{
		printf("Test 2 task passed successfully!!!\n");
	}
	else
	{
		printf("Failed!:((\n");
	}


	int n;
	scanf("%d", &n);
	return 0;
}

bool test_task_1(void)
{
	bool mas1[6]{ 1, 1, 0, 0, 1, 1 };
	bool mas2[5]{ 0, 0, 0, 1, 0 };
	bool mas3[6]{ 1, 1, 0, 1, 1, 1 };
	bool mas4[3]{ 1, 1, 0};
	bool mas5[4]{ 0, 1, 1, 0 };

	return FuncFromFirstTask(mas1, 6, mas2, 5) == 1 && FuncFromFirstTask(mas4, 3, mas5, 4) == 0 && FuncFromFirstTask(mas1, 6, mas3, 6) == 2;
}

int linearPow(int a, int n)
{
	if (n == 0)
	{
		return 1;
	}

	int b = 1;
	for (int i = 0; i < n; ++i)
	{
		b *= a;
	}
	return b;
}

int FuncFromFirstTask(bool *mas1, int length1, bool *mas2, int length2)
{
	int firstNumber = 0;
	int secondNumber = 0;
	for (int i = 0; i < length1; ++i)
	{
		if (mas1[i])
		{
			firstNumber += linearPow(2, length1 - i);
		}
	}
	for (int i = 0; i < length2; ++i)
	{
		if (mas2[i])
		{
			secondNumber += linearPow(2, length2 - i);
		}
	}
	if (firstNumber > secondNumber)
	{
		return 1;
	}
	else if (secondNumber > firstNumber)
	{
		return 2;
	}
	else
	{
		return 0;
	}
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