#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"

using namespace std;

bool test()
{
	auto table = createHashTable();
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
		add(table, buffer);
	}
	file.close();
	std::string testStr1 = "cover";
	std::string testStr2 = "this";
	std::string testStr3 = "ldldldl";
	std::string testStr4 = "room";
	if (findStr(table, testStr1) == 1 && findStr(table, testStr2) == 8 && findStr(table, testStr3) == 0 && findStr(table, testStr4) == 2)
	{
		deleteHashTable(table);
		return true;
	}
	deleteHashTable(table);
	return false;
}