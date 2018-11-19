#include <iostream>
#include <fstream>
#include <string>

#include "HashTable.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	auto table = createSet();
	constructor(*table);
	int amountOfElements = 0;
	ifstream file("TextFor9.1.txt");
	string buffer;
	if (!file.is_open())
	{
		cout << "Текст не открылся!!!\n";
		return 1;
	}
	while (!file.eof())
	{
		++amountOfElements;
		file >> buffer;
		add(*table, buffer);
	}
	printTable(*table);
	cout << "Коэффициент заполнения хэш-таблицы: " << loadFactor(*table, amountOfElements) << endl;



	return 0;
}