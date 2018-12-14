#include <fstream>
#include <iostream>
#include "list.h"
#include "Test.h"


int main()
{
	if (!test())
	{
		std::cout << "Test failed!\n";
		return 1;
	}
	auto list = createList();
	std::ifstream file("file.txt");
	while (!file.eof())
	{
		int buffer = 0;
		file >> buffer;
		push(list, buffer);
	}
	list = coupList(list);
	printList(list);
	file.close();
	deleteList(list);
	return 0;
}