#include <iostream>
#include <fstream>
#include "Test.h"
#include "TreeParseArithmyExpression.h"

int main()
{
	if (test())
	{
		std::cout << "Test passed!\n";
	}
	else
	{
		std::cout << "Test failed!\n";
		return -1;
	}

	std::ifstream file("ArithmeticExpression.txt");
	if (!file.is_open())
	{
		std::cout << "The file did not open!(\n";
		return -1;
	}

	std::string str;
	getline(file, str);
	std::cout << "Arithmitic expression result: " << resultArithmyExpression(str) << std::endl;

	file.close();
	return 0;
}
