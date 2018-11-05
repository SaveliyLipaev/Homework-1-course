#include "FunctionFor6.1.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	string inStr;
    cout << "¬ведите последовательность цифр и операци, представл€юща€ выражение в постфиксной форме\n";
	cin >> inStr;
	cout << "–езультат вычислени€: " << expressionResult(inStr) << endl;

	return 0;
}

