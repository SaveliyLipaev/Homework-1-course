#include "FuncForTest_3.2.h"
#include <iostream>

int maxInLine(std::vector<std::vector<int>> &matrix, const int columns, const int number)
{
	int max = _I32_MIN;
	int maxNumber = 0;
	for (int i = 0; i < columns; ++i)
	{
		if (matrix[number][i] > max)
		{
			max = matrix[number][i];
			maxNumber = i;
		}
	}
	return maxNumber;
}

int minInColumns(std::vector<std::vector<int>> &matrix, const int line, const int number)
{
	int min = INT32_MAX;
	int minNumber = 0;
	for (int i = 0; i < line; ++i)
	{
		if (matrix[i][number] < min)
		{
			min = matrix[i][number];
			minNumber = i;
		}
	}
	return minNumber;
}

void findSaddlePoints(std::vector<std::vector<int>> &matrix, const int line, const int columns)
{
	bool flagFind = false;
	for (int i = 0; i < line; ++i)
	{
		int max = maxInLine(matrix, columns, i);
		int min = minInColumns(matrix, line, max);
		if (min == i)
		{
			flagFind = true;
			std::cout << min + 1 << "  -  " << max + 1 << std::endl;
		}
	}
	if (!flagFind)
	{
		std::cout << "no saddle points found\n";
	}
}