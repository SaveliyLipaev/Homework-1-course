#include <iostream>

using namespace std;

struct listElement
{
	int data;
	listElement* next = nullptr;
};

struct SortedList 
{
	listElement *head = nullptr;
};

bool isEmpty(SortedList &list)
{
	return list.head == nullptr;
}

SortedList * createdSortedList()
{
	return new SortedList;
}

void pushList(SortedList &list, const int data)
{
	auto newElement = new listElement{ data, list.head };

	if (isEmpty(list))
	{
		list.head = newElement;
	}
	else
	{
		if (data <= list.head->data)
		{
			newElement->next = list.head;
			list.head = newElement;
		}
		else
		{
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
	}
}

void printList(SortedList &list)
{
	auto temp = list.head;
	while (temp != nullptr)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}

int main()
{
	auto list = createdSortedList();
	pushList(*list, 5);
	pushList(*list, 3);
	pushList(*list, 4);
	pushList(*list, 6);
	printList(*list);

	system("pause");
	return 0;
}