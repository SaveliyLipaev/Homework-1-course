#include "FunctionFor6.1.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	if (test())
	{
		cout << "Тест пройден!!\n\n";
	}
	else
	{
		cout << "Тест не пройден!!\n\n";
	}

	string inStr;
    cout << "Введите последовательность цифр и операций, представляющих выражение в постфиксной форме\n";
	cin >> inStr;
	cout << "Результат вычисления: " << expressionResult(inStr) << endl;

	return 0;
}

