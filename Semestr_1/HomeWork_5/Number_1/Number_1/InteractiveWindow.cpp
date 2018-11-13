#include <iostream>
#include "sortedList.h"
#include "InteractiveWindow.h"
using namespace std;

void interactiveWindows(SortedList *list)
{
	while (true)
	{
		system("cls");
		cout << "0 - выйти\n"
			 << "1 - добавить значение в сортированный список\n"
			 << "2 - удалить значение из списка\n"
			 << "3 - распечатать список" << endl;

		int temp = 0;
		cin >> temp;
		while (temp < 0 && temp > 3)
		{
			cout << "ќшибка ввода, повторите попытку:" << endl;
			cin >> temp;
		}

		switch (temp)
		{
		case 0:
		{
			return;
		}
		case 1:
		{
			addNode(list);
			break;
		}
		case 2:
		{
			deleteNode(list);
			break;
		}
		case 3:
		{
			printNodes(list);
			break;
		}
		}
	}
}

void addNode(SortedList *list)
{
	system("cls");
	int temp = 0;
	cout << "¬ведите значение которое хотите добавить в список:" << endl;
	while (!(cin >> temp))
	{
		cout << "ќшибка ввода, повторите попытку: " << endl;
	}
	pushList(list, temp);
}

void deleteNode(SortedList *list)
{
	system("cls");
	int temp = 0;
	cout << "¬ведите значение которое хотите удалить из списка:" << endl;
	while (!(cin >> temp))
	{
		cout << "ќшибка ввода, повторите попытку: " << endl;
	}
	deleteElement(list, temp);
}

void printNodes(SortedList *list)
{
	system("cls");
	printList(list);
	int temp = 0;
	cout << "¬ведите любое число дл€ продолжени€\n";
	cin >> temp;
}