#include <string>
#include <iostream>
#include <fstream>

struct ListNode
{
	std::string str;
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

void push(List *list, const std::string &name)
{
	list->head = new ListNode{ name, nullptr, list->head };

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

void merge(List *list, List *left, List *right)
{
	auto tempList = list->head;
	auto tempLeft = left->head;
	auto tempRight = right->head;

	while (tempRight != nullptr || tempLeft != nullptr)
	{
		if (tempLeft == nullptr || (tempRight != nullptr && tempLeft->str.compare(tempRight->str) > 0))
		{
			tempList->str = tempRight->str;
			tempRight = tempRight->next;
		}
		else
		{
			tempList->str = tempLeft->str;
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
		push(right, temp->str);
		temp = temp->previous;
	}

	for (int i = (list->length / 2); i > 0; --i)
	{
		push(left, temp->str);
		temp = temp->previous;
	}
}

void mergeSort(List *list)
{
	if (list->length == 1)
	{
		return;
	}

	auto left = createList();
	auto right = createList();

	split(list, left, right);

	mergeSort(left);
	mergeSort(right);

	merge(list, left, right);

	deleteList(left);
	deleteList(right);
}

void printListInFile(List *list, std::ofstream &file)
{
	auto temp = list->head;
	while (temp != nullptr)
	{
		file << temp->str << '\n';
		temp = temp->next;
	}
}

ListNode* findNode(List *&list, const std::string &str)
{
	if (list == nullptr)
	{
		list = createList();
	}
	auto temp = list->head;
	while (temp != nullptr)
	{
		if (temp->str == str)
		{
			return temp;
		}
		temp = temp->next;
	}
	return temp;
}