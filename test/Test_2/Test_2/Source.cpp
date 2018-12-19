#include <fstream>
#include <iostream>
#include "ListForTask.h"
#include "Test.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	if (testForTask2())
	{
		cout << "Тест пройден, все ок!\n\n";
	}
	cout << "ПЕРВОЕ ЗАДАНИЕ:\n\n";
	ifstream file("FileForTask_1.txt");
	if (!file.is_open())
	{
		cout << "Файл не открылся!!!\n";
		return -1;
	}
	cout << "Введите a и b:\n";
	int a = 0;
	int b = 0;
	cin >> a >> b;
	while (a >= b)
	{
		cout << "Ввод неверен, а должно быть менше чем b, повторите попытку:\n";
		cin >> a >> b;
	}
	auto listLessA = createList();
	auto listBetweenAAndB = createList();
	auto listLargeB = createList();
	push(listBetweenAAndB, a);
	push(listLargeB, b);
	while (!file.eof())
	{
		int buffer = 0;
		file >> buffer;
		if (buffer < a)
		{
			push(listLessA, buffer);
		}
		else if (buffer > b)
		{
			push(listLargeB, buffer);
		}
		else
		{
			push(listBetweenAAndB, buffer);
		}
	}
	file.close();
	printList(listLessA);
	printList(listBetweenAAndB);
	printList(listLargeB);

	deleteList(listBetweenAAndB);
	deleteList(listLargeB);
	deleteList(listLessA);

	cout << "\n\nВТОРОЕ ЗАДАНИЕ:\n\n";
	file.open("FileForTask_2.txt");
	if (!file.is_open())
	{
		cout << "Файл не открылся!!!\n";
		return -1;
	}
	auto list = createList();
	while (!file.eof())
	{
		int buffer = 0;
		file >> buffer;
		push(list, buffer);
	}
	if (thisListSymmetry(list))
	{
		cout << "Список симметричный!!!\n";
	}
	else
	{
		cout << "Список не симметричный!!!\n";
	}

	file.close();
	deleteList(list);
	return 0;
}