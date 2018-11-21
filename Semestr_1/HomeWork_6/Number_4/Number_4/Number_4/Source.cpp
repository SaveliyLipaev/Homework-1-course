#include <iostream>
#include <fstream>
#include "ListFor6.4.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	auto list = createList();
	std::ifstream file("Phonebook.txt");
	if (!file.is_open())
	{
		std::cout << "���� �� ��������\n";
		return 1;
	}

	std::string nameBuffer;
	std::string numberBuffer;

	while (!file.eof())
	{
		std::string nameBuffer;
		std::string numberBuffer;

		getline(file, nameBuffer);
		getline(file, numberBuffer);

		push(list, nameBuffer, numberBuffer);
	}

	std::cout << "0 - ������������� �� ������\n";
	std::cout << "1 - ������������� �� �����\n";

	int command = 2;
	std::cin >> command;
	while (command != 0 && command != 1)
	{
		std::cout << "������ �����, ��������� �������\n";
		std::cin >> command;
	}

	if (command == 0)
	{
		mergeSort(list, false);
	}
	else
	{
		mergeSort(list, true);
	}

	printList(list);

	deleteList(list);

	return 0;
}