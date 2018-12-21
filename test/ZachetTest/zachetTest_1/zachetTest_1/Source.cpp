#include <iostream>
#include <fstream>
#include <string>
#include "ListForSort.h"

int main()
{
	std::ifstream readFile("Text.txt");
	auto list = createList();

	while (!readFile.eof())
	{
		std::string buffer;
		getline(readFile, buffer);
		auto node = findNode(list, buffer);
		if (node == nullptr)
		{
			push(list, buffer);
		}
	}
	readFile.close();

	std::ofstream newFile("result.txt");

	mergeSort(list);

	printListInFile(list, newFile);

	newFile.close();
	deleteList(list);
	return 0;
}