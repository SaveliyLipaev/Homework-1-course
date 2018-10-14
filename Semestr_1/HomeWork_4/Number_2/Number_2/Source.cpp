#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <fstream>
#include "Head_MyFuncSem_1.h"

int amountWordsOrNumbers(FILE *file);

int main()
{
	FILE *file = fopen("FileForNumber_2.txt", "r");
	if (!file) 
	{
		printf("File not found!");
		return 1;
	}

	printf("%d", amountWordsOrNumbers(file));
	fclose(file);
	int n = 0;
	scanf("%d", &n);
	return 0;
}

int amountWordsOrNumbers(FILE *file)
{
	bool flagThisSpace = true;
	int amountNumbersInFile = 0;
	char charBuffer = 0;

	while (fscanf(file, "%c", &charBuffer) != EOF)
	{
		if (charBuffer == ' ' || charBuffer == '\n')
		{
			if (!flagThisSpace)
			{
				amountNumbersInFile++;
			}
			flagThisSpace = true;
		}
		else
		{
			flagThisSpace = false;
		}
	}
	if (!flagThisSpace)
	{
		amountNumbersInFile++;
	}
	return amountNumbersInFile;
}