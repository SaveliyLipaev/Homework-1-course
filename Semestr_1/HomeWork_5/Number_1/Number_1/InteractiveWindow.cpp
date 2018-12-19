#include <iostream>
#include "sortedList.h"
#include "InteractiveWindow.h"

void interactiveWindows(SortedList *list)
{
	while (true)
	{
		system("cls");
		std::cout << "0 - Exit\n"
			 << "1 - Add value to sorted list\n"
			 << "2 - Remove value from the list\n"
			 << "3 - Print list" << std::endl;

		int temp = 0;
		std::cin >> temp;
		while (temp < 0 && temp > 3)
		{
			std::cout << "Invalid input, try again:" << std::endl;
			std::cin >> temp;
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
	std::cout << "Enter what value do you want to add:" << std::endl;
	while (!(std::cin >> temp))
	{
		std::cout << "Invalid input, please try again: " << std::endl;
	}
	pushList(list, temp);
}

void deleteNode(SortedList *list)
{
	system("cls");
	int temp = 0;
	std::cout << "Enter which value you want to delete:" << std::endl;
	while (!(std::cin >> temp))
	{
		std::cout << "Invalid input, please try again: " << std::endl;
	}
	deleteElement(list, temp);
}

void printNodes(SortedList *list)
{
	system("cls");
	printList(list);
	int temp = 0;
	std::cout << "Enter any number to continue:\n";
	std::cin >> temp;
}