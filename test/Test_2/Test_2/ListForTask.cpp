#include <iostream>

struct ListNode
{
	int data;
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

void push(List *list, const int data)
{
	auto newNode = new ListNode{ data, nullptr, list->head };

	if (list->head == nullptr)
	{
		list->head = newNode;
		list->tail = newNode;
	}
	else
	{
		list->head = newNode;
		newNode->next->previous = newNode;
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

bool thisListSymmetry(List *list)
{
	if (list->length <= 1)
	{
		return true;
	}
	auto tempHead = list->head;
	auto tempTail = list->tail;
	for (int i = 0; i < list->length / 2; ++i)
	{
		if (tempHead->data != tempTail->data)
		{
			return false;
		}
		tempHead = tempHead->next;
		tempTail = tempTail->previous;
	}
	return true;
}

void printList(List *list)
{
	if (isEmpty(list))
	{
		return;
	}
	auto temp = list->tail;
	for (int i = 0; i < list->length; ++i)
	{
		std::cout << temp->data << ' ';
		temp = temp->previous;
	}
}