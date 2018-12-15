#include <iostream>
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
	auto newElement = new ListElement{ data, list->head };

	if (isEmpty(list))
	{
		list->head = newElement;
		return;
	}

	if (data <= list->head->data)
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
	else
	{
		auto temp = newElement->next->next;
		newElement->next->next = newElement;
		newElement->next = temp;
	}
}

void printList(SortedList *list)
{
	if (isEmpty(list))
	{
		std::cout << "The list is empty" << std::endl;
		return;
	}
	auto temp = list->head;
	while (temp != nullptr)
	{
		std::cout << temp->data << std::endl;
		temp = temp->next;
	}
}

void deleteElement(SortedList *list, const int data)
{
	if (isEmpty(list))
	{
		return;
	}
	auto temp = list->head;
	if (data == temp->data)
	{
		list->head = temp->next;
		delete temp;
		return;
	}
	while (temp->next != nullptr && temp->data < data)
	{
		if (temp->next->data == data)
		{
			auto tempTwo = temp->next;
			temp->next = temp->next->next;
			delete tempTwo;
			return;
		}
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

bool checkSortingList(SortedList *list)
{
	auto temp = list->head;

	if (temp == nullptr)
	{
		return true;
	}

	while (temp->next != nullptr)
	{
		if (temp->data > temp->next->data)
		{
			return false;
		}
		temp = temp->next;
	}
	return true;
}