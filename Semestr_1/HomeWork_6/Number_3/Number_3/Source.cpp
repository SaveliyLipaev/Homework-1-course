#include "infixToPostfixTranslation.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	if (test())
	{
		std::cout << "���� �������! ��� ������!\n";
	}
	else
	{
		std::cout << "���� ��������! ��� ���!\n";
	}
	return 0;
}