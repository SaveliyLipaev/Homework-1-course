#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <fstream>
#include "Head_MyFuncSem_1.h"

int amountSeriesOfCharacters(FILE *file);   //функция которая подсчитывает количество слов или чисел в файле
int maxLengthSeriesOfCharacter(FILE *file); //функция возвращающая длину самого длинного слова или серии символов

int main()
{
	FILE *file = fopen("FileForNumber_2.txt", "r");
	if (!file) 
	{
		printf("File not found!");
		return 1;
	}

	int amount = amountSeriesOfCharacters(file);
	int length = maxLengthSeriesOfCharacter(file);

	char** buffer = new char*[amount];
	for (int i = 0; i < amount; ++i)
	{
		buffer[i] = new char[length]{};
	}

	rewind(file);
	
	for (int i = 0, j = 0; fscanf(file, "%c", &buffer[i][j]) != EOF;)
	{
		if (buffer[i][j] == ' ' || buffer[i][j] == '\n')
		{
			if (j >= 1 && buffer[i][j - 1] != ' ' && buffer[i][j - 1] != '\n')
			{
				++i;
				j = 0;
			}
			continue;
		}
		++j;
	}

	for (int i = 0; i < amount; ++i)
	{
		for (int j = 0; j < length; ++j)
			printf("%c ", buffer[i][j]);
		printf("\n");
	}


	for (int i = 0; i < amount; ++i)
	{
		delete[] buffer[i];
	}
	fclose(file);
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