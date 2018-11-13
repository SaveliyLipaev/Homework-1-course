#include "sortedList.h"


bool test()
{
	SortedList *list = createdSortedList();

	for (int i = 50; i >= 0; --i)
	{
		pushList(list, i);
		pushList(list, i - 25);
		if (!checkSortingList(list))
		{
			deleteList(list);
			return false;
		}
	}

	for (int i = 0; i <= 50; ++i)
	{
		deleteElement(list, i);
		deleteElement(list, i - 25);
		if (!checkSortingList(list))
		{
			deleteList(list);
			return false;
		}
	}

	if (!isEmpty(list))
	{
		deleteList(list);
		return false;
	}

	deleteList(list);
	return true;
}