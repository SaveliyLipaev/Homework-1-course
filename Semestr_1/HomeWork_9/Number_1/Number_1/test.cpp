#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"

using namespace std;

bool test()
{
	auto table = createHashTable();
	constructor(*table);
	ifstream file("TextFor9.1.txt");
	string buffer;

	if (!file.is_open())
	{
		cout << "Текст не открылся!!!\n";
		return false;
	}
	while (!file.eof())
	{
		file >> buffer;
		add(*table, buffer);
	}

	if (findStr(*table, "cover") == 1 && findStr(*table, "this") == 8 && findStr(*table, "ldldldl") == 0 && findStr(*table, "room") == 2)
	{
		deleteHashTable(*table);
		return true;
	}
	deleteHashTable(*table);
	return false;
}