#include "FunctionFor6.1.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	if (test())
	{
		cout << "���� �������!!\n\n";
	}
	else
	{
		cout << "���� �� �������!!\n\n";
	}

	string inStr;
    cout << "������� ������������������ ���� � ��������, �������������� ��������� � ����������� �����\n";
	cin >> inStr;
	cout << "��������� ����������: " << expressionResult(inStr) << endl;

	return 0;
}

