#include <iostream>
#include "cyclicList.h"
#include "test.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	if (test())
	{
		cout << "���� �������!\n\n";
	}
	else
	{
		cout << "���� �� �������!\n\n";
	}

	auto list = createCyclicList();
	int warriors = 0;
	int step = 0;

	cout << "������� ���������� ������\n";
	cin >> warriors;
	cout << "������� ������� ������ ����� �������\n";
	cin >> step;
	
	for (int i = warriors; i >= 1; --i)
	{
		push(list, i);
	}

	cout << "��������� ����, ������� ����� �� " << deleteWithStep(list, step) << "-�� �������" << endl;

	deleteList(list);
	return 0;
}