#include "infixToPostfixTranslation.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	if (test())
	{
		std::cout << "Тест пройден! Все хорошо!\n";
	}
	else
	{
		std::cout << "Тест провален! Алл бэд!\n";
	}
	return 0;
}