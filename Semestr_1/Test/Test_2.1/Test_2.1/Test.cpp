#include "list.h"
#include <fstream>


bool test()
{
	auto list = createList();
	std::ifstream file("file.txt");
	while (!file.eof())
	{
		int buffer = 0;
		file >> buffer;
		push(list, buffer);
	}
	file.close();
	list = coupList(list);
	if (pop(list) != 1)
	{
		deleteList(list);
		return false;
	}
	if (pop(list) != 2)
	{
		deleteList(list);
		return false;
	}
	if (pop(list) != 3)
	{
		deleteList(list);
		return false;
	}
	deleteList(list);
	return true;
}