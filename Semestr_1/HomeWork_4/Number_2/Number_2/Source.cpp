#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <fstream>
#include "Head_MyFuncSem_1.h"

int amountSeriesOfCharacters(FILE *file);
int maxLengthSeriesOfCharacter(FILE *file);

int main()
{
	FILE *file = fopen("FileForNumber_2.txt", "r");
	if (!file) 
	{
		printf("File not found!");
		return 1;
	}

	//int amount = amountSeriesOfCharacters(file);
	//char** buffer = new char*[amount];
	//for(int i=0;i<)



	printf("%d\n", maxLengthSeriesOfCharacter(file));
	printf("%d", amountSeriesOfCharacters(file));
	fclose(file);
	int n = 0;
	scanf("%d", &n);
	return 0;
}

int amountSeriesOfCharacters(FILE *file)
{
	rewind(file);
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

int maxLengthSeriesOfCharacter(FILE *file)
{
	rewind(file);
	bool flagThisSpace = true;
	int maxLengthCharacterInFile = 0;
	int helpVeriable = 0;
	char charBuffer = 0;

	while (fscanf(file, "%c", &charBuffer) != EOF)
	{
		if (charBuffer == ' ' || charBuffer == '\n')
		{
			flagThisSpace = true;
		}
		else
		{
			flagThisSpace = false;
			++helpVeriable;
		}
		if (flagThisSpace)
		{
			if (helpVeriable > maxLengthCharacterInFile)
			{
				maxLengthCharacterInFile = helpVeriable;
			}
			helpVeriable = 0;
		}
	}
	if (helpVeriable > maxLengthCharacterInFile)
	{
		maxLengthCharacterInFile = helpVeriable;
	}
	return maxLengthCharacterInFile;
}