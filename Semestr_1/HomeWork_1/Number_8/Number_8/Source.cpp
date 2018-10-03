#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int number, counter = 0;
	printf("Enter the number of elements in the array\n");
	scanf("%d", &number);
	printf("Enter the elements in the array\n");
	int* mas = new int[number];
	for (int i = 0; i < number; ++i)
	{
		scanf("%d", &mas[i]);
		if (mas[i] == 0)
		{
			++counter;
		}
	}
	printf("Number of zero elements: %d\n", counter);
	delete[] mas;
	return 0;
}