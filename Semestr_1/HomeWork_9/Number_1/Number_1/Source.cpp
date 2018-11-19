#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"
#include "test.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	if (test())
	{
		auto table = createHashTable();
		constructor(*table);

		ifstream file("TextFor9.1.txt");
		string buffer;

		if (!file.is_open())
		{
			cout << "����� �� ��������!!!\n";
			return 1;
		}
		while (!file.eof())
		{
			file >> buffer;
			add(*table, buffer);
		}

		printTable(*table);
		cout << "����������� ���������� ���-�������: " << loadFactor(*table) << endl;
		cout << "������������ ����� ������ � �������� �������: " << maxLength(*table) << endl;
		cout << "������� ����� ������ � �������� �������: " << averageLength(*table) << endl;

		deleteHashTable(*table);
	}
	else
	{
		cout << "���� �� �������!!!\n";
	}
	return 0;
}