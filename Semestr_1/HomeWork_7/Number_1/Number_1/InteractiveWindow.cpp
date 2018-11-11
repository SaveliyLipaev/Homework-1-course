
#include "BST.h"
#include "InteractiveWindow.h"

void interactiveWindows(BST *tree)
{
	while (true)
	{
		system("cls");
		cout << "0 - �����\n"
			<< "1 - �������� �������� � ���������\n"
			<< "2 - ������� ��������\n"
			<< "3 - ���������, ����������� �� �������� ���������\n"
			<< "4 - ����������� ������� �������� ��������� � ������������ �������\n"
			<< "5 - ����������� ������� �������� ��������� � ��������� �������\n" << endl;

		int temp = 0;
		cin >> temp;
		while (temp < 0 && temp > 5)
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
			cout << "������� ����� ����� ��� �����������";
			int helper = 0;
			cin >> helper;
			break;
		}
		case 5:
		{
			printIncreasing(tree);
			cout << "������� ����� ����� ��� �����������";
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
	cout << "������� ����� �������� ������ ��������: \n";
	cin >> temp;
	add(tree, temp);
}

void deleteElement(BST *tree)
{
	int temp = 0;
	cout << "������� ����� �������� ������ �������: \n";
	cin >> temp;
	terriblyUglyDeleteNode(tree, temp);
}

void affiliationElement(BST *tree)
{
	int temp = 0;
	cout << "������� ����� �������� ������ ���������: \n";
	cin >> temp;
	if (find(tree, temp))
	{
		cout << "�������� ����������� ���������!\n";
	}
	else
	{
		cout << "�������� �� ���������� ���������!\n";
	}
	cout << "������� ����� ����� ����� ����������:\n";
	cin >> temp;
}