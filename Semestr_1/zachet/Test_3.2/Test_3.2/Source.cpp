#include <vector>
#include <iostream>
#include "FuncForTest_3.2.h"


int main()
{
	std::cout << "Enter the number of line and columns\n";
	int line = 0;
	int columns = 0;
	std::cin >> line >> columns;
	std::vector<std::vector<int>> matrix(line, std::vector<int>(columns));
	std::cout << "Enter the matrix\n";
	for (int i = 0; i < line; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			std::cin >> matrix[i][j];
		}
	}
	findSaddlePoints(matrix, line, columns);
	return 0;
}