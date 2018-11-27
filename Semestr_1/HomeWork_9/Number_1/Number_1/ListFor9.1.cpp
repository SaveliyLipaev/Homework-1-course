#include <string>
#include <iostream>

using namespace std;

struct NodeList
{
	std::string str;
	int quantity = 1;
	NodeList *next;
};

struct List
{
	NodeList *head = nullptr;
};

bool isEmpty(List *list)
{
	return list->head == nullptr;
}

List* createList()
{
	return new List;
}

NodeList* findNode(List *&list, const string &str)
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

void push(List *list, const string &str)
{
	auto newNode = new NodeList{ str, 1, list->head };
	list->head = newNode;
}

void pop(List *list)
{
	auto temp = list->head;
	list->head = temp->next;
	delete temp;
}

void deleteList(List *list)
{
	if (list == nullptr)
	{
		return;
	}
	while (list->head != nullptr)
	{
		auto temp = list->head;
		list->head = temp->next;
		delete temp;
	}
	delete list;
}

void printList(List *list)
{
	if (list == nullptr)
	{
		return;
	}
	auto temp = list->head;
	while (temp != nullptr)
	{
		cout << temp->str << " - " << temp->quantity << endl;
		temp = temp->next;
	}
}

void increaseQuantity(NodeList *node)
{
	++node->quantity;
}

int lengthList(List *list)
{
	if (list == nullptr)
	{
		return 0;
	}
	int length = 0;
	auto temp = list->head;
	while (temp != nullptr)
	{
		++length;
		temp = temp->next;
	}
	return length;
}

int returnQuantity(NodeList *node)
{
	return node->quantity;
}