#include <iostream>
#include <fstream>
#include "Test.h"
#include "TreeParseArithmyExpression.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	if (test())
	{
		std::cout << "Тест пройден, все ок!\n";
	}
	else
	{
		std::cout << "Тест провален!\n";
		return -1;
	}

	std::ifstream file("ArithmeticExpression.txt");
	if (!file.is_open())
	{
		std::cout << "Файл не открылся!(\n";
		return -1;
	}

	std::string str;
	getline(file, str);
	std::cout << "Результат арифмитического выражения: " << resultArithmyExpression(str) << std::endl;

	file.close();
	return 0;
}
