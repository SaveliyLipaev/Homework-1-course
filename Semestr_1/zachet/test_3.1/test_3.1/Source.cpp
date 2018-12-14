#include <iostream>
#include "sortedList.h"

int main()
{
	auto list = createdSortedList();
	int buffer = 1;
	std::cout << "Enter numbers:\n";
	std::cin >> buffer;
	while (buffer != 0)
	{
		pushList(list, buffer);
		std::cin >> buffer;
	}
	std::cout << "RESULT:\n";
	printList(list);

	deleteList(list);
	return 0;
}
