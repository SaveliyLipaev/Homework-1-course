#include "infixToPostfixTranslation.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	if (test())
	{
		cout << "���� �������! ��� ������!\n";
	}
	else
	{
		cout << "���� ��������! ��� ���!\n";
	}
	return 0;
}