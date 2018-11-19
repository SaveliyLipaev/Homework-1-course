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
			cout << "Текст не открылся!!!\n";
			return 1;
		}
		while (!file.eof())
		{
			file >> buffer;
			add(*table, buffer);
		}

		printTable(*table);
		cout << "Коэффициент заполнения хэш-таблицы: " << loadFactor(*table) << endl;
		cout << "Максимальная длина списка в сегменте таблицы: " << maxLength(*table) << endl;
		cout << "Средняя длина списка в сегменте таблицы: " << averageLength(*table) << endl;

		deleteHashTable(*table);
	}
	else
	{
		cout << "Тест не пройден!!!\n";
	}
	return 0;
}