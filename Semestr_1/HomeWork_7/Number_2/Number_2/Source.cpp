#include <iostream>
#include <fstream>
#include "Test.h"
#include "TreeParseArithmyExpression.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	if (test())
	{
		std::cout << "���� �������, ��� ��!\n";
	}
	else
	{
		std::cout << "���� ��������!\n";
		return -1;
	}

	std::ifstream file("ArithmeticExpression.txt");
	if (!file.is_open())
	{
		std::cout << "���� �� ��������!(\n";
		return -1;
	}

	std::string str;
	getline(file, str);
	std::cout << "��������� ��������������� ���������: " << resultArithmyExpression(str) << std::endl;

	file.close();
	return 0;
}
