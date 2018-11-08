#include "infixToPostfixTranslation.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	if (test())
	{
		cout << "Тест пройден! Все хорошо!\n";
	}
	else
	{
		cout << "Тест провален! Алл бэд!\n";
	}
	return 0;
}