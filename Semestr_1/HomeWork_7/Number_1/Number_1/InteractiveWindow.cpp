
#include "BST.h"
#include "InteractiveWindow.h"

void interactiveWindows(BST *tree)
{
	while (true)
	{
		system("cls");
		cout << "0 - Выход\n"
			<< "1 - Добавить значение в множество\n"
			<< "2 - Удалить значение\n"
			<< "3 - Проверить, принадлежит ли значение множеству\n"
			<< "4 - Распечатать текущие элементы множества в возрастающем порядке\n"
			<< "5 - Распечатать текущие элементы множества в убывающем порядке\n" << endl;

		int temp = 0;
		cin >> temp;
		while (temp < 0 && temp > 5)
		{
			cout << "Ошибка ввода, повторите попытку:" << endl;
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
			addElement(tree);
			break;
		}
		case 2:
		{
			deleteElement(tree);
			break;
		}
		case 3:
		{
			affiliationElement(tree);
			break;
		}
		case 4:
		{
			printDecreasing(tree);
			cout << "Введите любое число для продолжения";
			int helper = 0;
			cin >> helper;
			break;
		}
		case 5:
		{
			printIncreasing(tree);
			cout << "Введите любое число для продолжения";
			int helper = 0;
			cin >> helper;
			break;
		}
		}
	}
}

void addElement(BST *tree)
{
	int temp = 0;
	cout << "Введите какое значение хотите добавить: \n";
	cin >> temp;
	add(tree, temp);
}

void deleteElement(BST *tree)
{
	int temp = 0;
	cout << "Введите какое значение хотите удалить: \n";
	cin >> temp;
	terriblyUglyDeleteNode(tree, temp);
}

void affiliationElement(BST *tree)
{
	int temp = 0;
	cout << "Введите какое значение хотите проверить: \n";
	cin >> temp;
	if (find(tree, temp))
	{
		cout << "Значение принадлежит множеству!\n";
	}
	else
	{
		cout << "Значение не принадлжет множеству!\n";
	}
	cout << "Введите любое число чтобы продолжить:\n";
	cin >> temp;
}