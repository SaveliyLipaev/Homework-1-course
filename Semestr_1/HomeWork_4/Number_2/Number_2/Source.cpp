#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <fstream>
#include "Head_MyFuncSem_1.h"

int main()
{
	FILE *file = fopen("FileForNumber_2.txt", "r");
	if (!file) 
	{
		printf("File not found!");
		return 1;
	}

	int temp = 0;
	int counter = 0;

	while (fscanf(file, "%d", &temp) != EOF)
	{
		++counter;
	}

	rewind(file);
	int *mas = new int[counter];

	for (int i = 0; i < counter; ++i)
	{
		fscanf(file, "%d", &mas[i]);
	}

	printf("The most common element in the file: %d\n",mostCommonElement(mas, counter));

	fclose(file);
	delete[] mas;
	return 0;
}
