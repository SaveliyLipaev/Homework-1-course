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

bool isEmpty(List *list)
{
	return list->head == nullptr;
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

void merge(List *list, List *left, List *right, const bool byName)
{
	auto tempList = list->head;
	auto tempLeft = left->head;
	auto tempRight = right->head;

	while (tempRight != nullptr || tempLeft != nullptr)
	{
		if (tempLeft == nullptr || (tempRight != nullptr && (byName ? tempLeft->name.compare(tempRight->name) : tempLeft->number.compare(tempRight->number)) > 0))
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

	auto left = createList();
	auto right = createList();

	split(list, left, right);

	mergeSort(left, byName);
	mergeSort(right, byName);

	merge(list, left, right, byName);

	deleteList(left);
	deleteList(right);
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

bool checkSort(List *list, const bool byName)
{
	if (isEmpty(list))
	{
		return true;
	}
	auto temp = list->head->next;
	while (temp != nullptr)
	{
		if ((byName ? temp->name.compare(temp->previous->name) : temp->number.compare(temp->previous->number)) < 0)
		{
			return false;
		}
		temp = temp->next;
	}
	return true;
}