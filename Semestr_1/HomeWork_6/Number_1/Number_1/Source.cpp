#include "FunctionFor6.1.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	string inStr;
    cout << "������� ������������������ ���� � �������, �������������� ��������� � ����������� �����\n";
	cin >> inStr;
	cout << "��������� ����������: " << expressionResult(inStr) << endl;

	return 0;
}

