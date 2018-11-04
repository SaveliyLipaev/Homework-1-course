#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctime>
#include <cstdlib>

void swap(int& a, int& b);
int partition(int* mas, const int left, const int right);
void qusort(int* mas, const int left, const int right);
bool binSearch(int* mas, const int left, const int right, const int searchVeriable);
bool test();

int main()
{
	if (test)
	{
		printf("The test was successful\n");
	}
	else
	{
		printf("The test was failed\n");
	}

	srand(time(nullptr));
	int n = 0;
	int k = 0;

	printf("Enter n and k:");
	scanf("%d%d", &n, &k);
	int * mas = new int[n];

	printf("Source array: \n");
	for (int i = 0; i < n; ++i)
	{
		mas[i] = (rand() % 1000 + 1) * (rand() % 1000 + 1) * (rand() % 1000 + 1);
		printf("%d\n", mas[i]);
	}

	qusort(mas, 0, n - 1);
	
	for (int i = 0; i < k; ++i)
	{
		const int randomVariable = (rand() % 1000 + 1) * (rand() % 1000 + 1) * (rand() % 1000 + 1);
		printf("Number %d", randomVariable);
		if (binSearch(mas, 0, n - 1, randomVariable))
		{
			printf(" is present\n");
		}
		else
		{
			printf(" not present\n");
		}
	}
	delete[] mas;
	return 0;
}

bool test() 
{
	int array1[10]{ 23, 14, 53, 9, 53, 1, 90, 5, 53, 1 };
	int array2[10]{ -43, -33, 0, 12, 45, -5, 111, -555, 0, -33 };
	qusort(array1, 0, 9);
	qusort(array2, 0, 9);

	return binSearch(array1, 0, 9, 33) == false && binSearch(array1, 0, 9, 90) == true && binSearch(array2, 0, 9, 3) == false && binSearch(array2, 0, 9, -33) == true;
}

bool binSearch(int* mas, const int left, const int right, const int searchVeriable)
{
	const unsigned int average = (right + left) / 2;

	if (left >= right)
	{
		return mas[left] == searchVeriable;
	}

	if (mas[average] == searchVeriable)
	{
		return true;
	}

	if (mas[average] > searchVeriable)
	{
		return binSearch(mas, left, average - 1 , searchVeriable);
	}

	if (mas[average] < searchVeriable)
	{
		return binSearch(mas, average + 1 , right, searchVeriable);
	}
}

void swap(int &a, int &b)
{
	const int c = a;
	a = b;
	b = c;
}

int partition(int* mas, const int left, const int right)
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

void qusort(int* mas, const int left, const int right)
{
	if (right < left)
	{
		return;
	}
	const unsigned int p = partition(mas, left, right);
	qusort(mas, left, p - 1);
	qusort(mas, p + 1, right);
}
