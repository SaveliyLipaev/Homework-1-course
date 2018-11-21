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
		std::cout << "Файл не открылся\n";
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

	std::cout << "0 - отсортировать по номеру\n";
	std::cout << "1 - отсортировать по имени\n";

	int command = 2;
	std::cin >> command;
	while (command != 0 && command != 1)
	{
		std::cout << "ошибка ввода, повторите попытку\n";
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