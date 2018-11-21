#include <string>
#include <iostream>

struct ListNode
{
	std::string name;
	std::string number;
	ListNode *previous = nullptr;
	ListNode *next = nullptr;
};

struct List
{
	int length = 0;
	ListNode *head = nullptr;
	ListNode *tail = nullptr;
};

List* createList()
{
	return new List;
}

void push(List *list, const std::string name, const std::string number)
{
	list->head = new ListNode{ name, number, nullptr, list->head };

	if (list->head->next == nullptr)
	{
		list->tail = list->head;
	}
	else
	{
		list->head->next->previous = list->head;
	}

	++list->length;
}

void deleteList(List *list)
{
	while (list->head != nullptr)
	{
		auto temp = list->head;
		list->head = temp->next;
		delete temp;
	}
	delete list;
}

void sortByName(List *list, List *left, List *right)
{
	auto tempList = list->head;
	auto tempLeft = left->head;
	auto tempRight = right->head;

	while (tempRight != nullptr || tempLeft != nullptr)
	{
		if (tempLeft == nullptr || (tempRight != nullptr && tempLeft->name.compare(tempRight->name) > 0))
		{
			tempList->name = tempRight->name;
			tempList->number = tempRight->number;
			tempRight = tempRight->next;
		}
		else
		{
			tempList->name = tempLeft->name;
			tempList->number = tempLeft->number;
			tempLeft = tempLeft->next;
		}
		tempList = tempList->next;
	}
}

void sortByNumber(List *list, List *left, List *right)
{
	auto tempList = list->head;
	auto tempLeft = left->head;
	auto tempRight = right->head;

	while (tempRight != nullptr || tempLeft != nullptr)
	{
		if (tempLeft == nullptr || tempLeft->name.compare(tempRight->number) > 0)
		{
			tempList->name = tempRight->name;
			tempList->number = tempRight->number;
			tempRight = tempRight->next;
		}
		else
		{
			tempList->name = tempLeft->name;
			tempList->number = tempLeft->number;
			tempLeft = tempLeft->next;
		}
		tempList = tempList->next;
	}
}

void split(List *list, List *left, List *right)
{
	auto temp = list->tail;

	for (int i = list->length; i > list->length / 2; --i)
	{
		push(right, temp->name, temp->number);
		temp = temp->previous;
	}

	for (int i = (list->length / 2); i > 0; --i)
	{
		push(left, temp->name, temp->number);
		temp = temp->previous;
	}
}

void mergeSort(List *list, const bool byName)
{
	if (list->length == 1)
	{
		return;
	}

	List left;
	List right;

	split(list, &left, &right);

	mergeSort(&left, byName);
	mergeSort(&right, byName);

	if (byName)
	{
		sortByName(list, &left, &right);
	}
	else
	{
		sortByNumber(list, &left, &right);
	}
}

void printList(List *list)
{
	auto temp = list->head;
	while (temp != nullptr)
	{
		std::cout << temp->name << std::endl << temp->number << std::endl << std::endl;
		temp = temp->next;
	}
}