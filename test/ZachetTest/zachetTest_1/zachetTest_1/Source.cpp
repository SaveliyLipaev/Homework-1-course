#include <iostream>
#include <fstream>
#include <string>
#include "ListForSort.h"


using namespace std;

int main()
{
	ifstream readFile("Text.txt");
	auto list = createList();

	while (!readFile.eof())
	{
		string buffer;
		getline(readFile, buffer);
		auto node = findNode(list, buffer);
		if (node == nullptr)
		{
			push(list, buffer);
		}
	}
	readFile.close();
	ofstream newFile("result.txt");
	mergeSort(list);
	printListInFile(list, newFile);
	newFile.close();
	deleteList(list);
	return 0;
}