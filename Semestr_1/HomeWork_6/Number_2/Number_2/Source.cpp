#include "FunctionFor6.2.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	if (test())
	{
		cout << "Тест пройден! Все работает!" << endl;
	}
	else
	{
		cout << "Ошибка!!!" << endl;
	}

	return 0;
}