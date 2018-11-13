#include <iostream>
#include "sortedList.h"
#include "InteractiveWindow.h"
using namespace std;

void interactiveWindows(SortedList *list)
{
	while (true)
	{
		system("cls");
		cout << "0 - �����\n"
			 << "1 - �������� �������� � ������������� ������\n"
			 << "2 - ������� �������� �� ������\n"
			 << "3 - ����������� ������" << endl;

		int temp = 0;
		cin >> temp;
		while (temp < 0 && temp > 3)
		{
			cout << "������ �����, ��������� �������:" << endl;
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
	cout << "������� �������� ������� ������ �������� � ������:" << endl;
	while (!(cin >> temp))
	{
		cout << "������ �����, ��������� �������: " << endl;
	}
	pushList(list, temp);
}

void deleteNode(SortedList *list)
{
	system("cls");
	int temp = 0;
	cout << "������� �������� ������� ������ ������� �� ������:" << endl;
	while (!(cin >> temp))
	{
		cout << "������ �����, ��������� �������: " << endl;
	}
	deleteElement(list, temp);
}

void printNodes(SortedList *list)
{
	system("cls");
	printList(list);
	int temp = 0;
	cout << "������� ����� ����� ��� �����������\n";
	cin >> temp;
}