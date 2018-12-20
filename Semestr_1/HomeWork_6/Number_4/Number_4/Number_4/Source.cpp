#include <iostream>
#include <fstream>
#include "ListFor6.4.h"
#include "test.h"

int main()
{
	if (test())
	{
		std::cout << "Тест пройден, все ок!!!\n\n";
	}
	else
	{
		std::cout << "Тест провален!!!\n\n";
		return 1;
	}

	std::ifstream file("Phonebook.txt");
	if (!file.is_open())
	{
		std::cout << "Файл не открылся\n";
		return 1;
	}

	auto list = createList();

	while (!file.eof())
	{
		std::string nameBuffer;
		std::string numberBuffer;

		getline(file, nameBuffer);
		getline(file, numberBuffer);

		push(list, nameBuffer, numberBuffer);
	}

	file.close();

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