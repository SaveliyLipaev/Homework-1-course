#include <iostream>
#include "sortedList.h"

struct ListElement
{
	int numberOfEntries = 1;
	int data;
	ListElement* next = nullptr;
};

struct SortedList
{
	ListElement *head = nullptr;
};

SortedList * createdSortedList()
{
	return new SortedList;
}

bool isEmpty(SortedList *list)
{
	return list->head == nullptr;
}

void pushList(SortedList *list, const int data)
{
	auto newElement = new ListElement{ 1,data, list->head };
	if (isEmpty(list))
	{
		list->head = newElement;
		return;
	}
	if (data == list->head->data)
	{
		++list->head->numberOfEntries;
		return;
	}
	if (data < list->head->data)
	{
		newElement->next = list->head;
		list->head = newElement;
		return;
	}
	while (newElement->next->next != nullptr && newElement->data > newElement->next->next->data)
	{
		newElement->next = newElement->next->next;
	}
	if (newElement->next->next == nullptr)
	{
		newElement->next->next = newElement;
		newElement->next = nullptr;
	}
	else if (newElement->data == newElement->next->next->data)
	{
		newElement->next->next->numberOfEntries++;
		return;
	}
	else
	{
		auto temp = newElement->next->next;
		newElement->next->next = newElement;
		newElement->next = temp;
	}
}

void printList(SortedList *list)
{
	auto temp = list->head;
	while (temp != nullptr)
	{
		std::cout << temp->data << "  -  " << temp->numberOfEntries << std::endl;
		temp = temp->next;
	}
}

void deleteList(SortedList *list)
{
	while (list->head != nullptr)
	{
		auto temp = list->head;
		list->head = list->head->next;
		delete temp;
	}
}