#include "sortedList.h"

struct ListElement
{
	int data;
	ListElement* next = nullptr;
};

struct SortedList
{
	ListElement *head = nullptr;
};

bool test()
{
	auto list = createdSortedList();

	pushList(list, 10);
	if (list->head->data != 10)
	{
		return false;
	}

	pushList(list, 20);
	if (list->head->data != 10)
	{
		return false;
	}

	deleteElement(list, 10);
	if (list->head->data != 20)
	{
		return false;
	}

	deleteList(list);
	if (isEmpty(list))
	{
		delete list;
		return true;
	}
	delete list;
	return false;
}