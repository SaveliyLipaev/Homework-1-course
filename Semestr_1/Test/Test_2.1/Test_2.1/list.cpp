#include <iostream>

struct Node
{
	int data;
	Node *next;
};

struct List
{
	int length = 0;
	Node *head = nullptr;
};

List *createList()
{
	return new List;
}

void push(List *list, int data)
{
	auto newNode = new Node{ data, list->head };
	list->head = newNode;
	++list->length;
}

int pop(List *list)
{
	auto temp = list->head;
	const int value = temp->data;
	list->head = temp->next;
	delete temp;
	return value;
}

bool isEmpty(List *list)
{
	return list->head == nullptr;
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

int lastValue(List *list)
{
	return list->head->data;
}

List* coupList(List *list)
{
	auto newList = createList();
	for (int i = 0; i < list->length; ++i)
	{
		push(newList, pop(list));
	}
	deleteList(list);
	return newList;
}

void printList(List *list)
{
	auto temp = list->head;
	while (temp->next != nullptr)
	{
		std::cout << temp->data << std::endl;
		temp = temp->next;
	}
}