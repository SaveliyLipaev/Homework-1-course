#include <iostream>
#include "sortedList.h"
#include "InteractiveWindow.h"

int main()
{
	if (test())
	{
		SortedList* list = createdSortedList();

		interactiveWindows(list);

		deleteList(list);
		delete list;
	}
	else
	{
		std::cout << "Test failed!!\n";
	}
	return 0;
}