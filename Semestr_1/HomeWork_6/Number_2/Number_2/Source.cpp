#include "FunctionFor6.2.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	if (test())
	{
		cout << "���� �������! ��� ��������!" << endl;
	}
	else
	{
		cout << "������!!!" << endl;
	}

	return 0;
}