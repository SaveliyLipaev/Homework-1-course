#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>

struct Contact
{
	char name[30]{};
	int number;
};

void backButton(void)
{
	printf("0 - �����\n");
	int temp = 0;
	scanf("%d", &temp);
	while (temp != 0)
	{
		scanf("%d", &temp);
	}
}

void printNote(Contact *mas, const int numberOldNote, const int numberNewNote)
{
	system("cls");
	for (int i = 0; i < numberOldNote + numberNewNote; ++i)
	{
		printf("%s  -  %d\n", mas[i].name, mas[i].number);
	}
	printf("0 - �����\n");
	int temp = 0;
	scanf("%d", &temp);
	while (temp != 0)
	{
		scanf("%d", &temp);
	}
}

void saveNewNote(Contact *mas, int &numberOldNote, int &numberNewNote)
{
	FILE *file = fopen("phonebook.txt", "a");
	for (int i = numberOldNote; i < numberOldNote + numberNewNote; ++i)
	{
		fprintf(file, "%s    %d\n", mas[i].name, mas[i].number);
	}
	fclose(file);
	numberOldNote += numberNewNote;
	numberNewNote = 0;
}

void searchName(Contact *mas, const int numberOldNote)
{
	system("cls");
	printf("����� ����� �� �������� \n������� ����� ��������\n");
	int number = 0;
	scanf("%d", &number);
	for (int i = 0; i < numberOldNote; ++i)
	{
		if (mas[i].number == number)
		{
			printf("������ ����� ��������: %s\n", mas[i].name);
			backButton();
			return;
		}
	}
	printf("�������� � ����� ������� �� �������!\n");
	backButton();
}

void searchNumber(Contact *mas, const int numberOldNote)
{
	system("cls");
	printf("����� �������� �� ����� \n������� ���\n");
	char name[40]{};
	scanf("%s", name);
	for (int i = 0; i < numberOldNote; ++i)
	{
		if (!strcmp(mas[i].name, name))
		{
			printf("������� ����� ��������: %d\n", mas[i].number);
			backButton();
			return;
		}
	}
	printf("����� ����� ��������� �� ������!\n");
	backButton();
}

void addNote(Contact *mas, const int numberOldNote, int &numberNewNote)
{
	system("cls");
	printf("������� ���\n");
	scanf("%s", &mas[numberOldNote + numberNewNote].name);
	printf("\n������� �����\n");
	scanf("%d", &mas[numberOldNote + numberNewNote].number);
	++numberNewNote;
}

void interactiveWindow()
{
	Contact buffer[100]{};
	int numberOldNote = 0;
	int numberNewNote = 0;
	FILE *file = fopen("phonebook.txt", "r");
	if (file == nullptr)
	{
		printf("����� ����!\n");
	}

	while (fscanf(file, "%s%d", &buffer[numberOldNote].name, &buffer[numberOldNote].number) != EOF)
	{
		++numberOldNote;
	}
	fclose(file);
	while (true)
	{
		system("cls");
		printf("0 - �����\n1 - �������� ������\n2 - ����������� ��� ��������� ������\n3 - ����� ������� �� ������\n4 - ����� ��� �� ��������\n5 - ��������� ������� ������ � ����\n");
		int temp = 0;
		scanf("%d", &temp);
		switch (temp)
		{
		case 0:
		{
			return;
		}
		case 1:
		{
			addNote(buffer, numberOldNote, numberNewNote);
			break;
		}
		case 2:
		{
			printNote(buffer, numberOldNote, numberNewNote);
			break;
		}
		case 3:
		{
			searchNumber(buffer, numberOldNote);
			break;
		}
		case 4:
		{
			searchName(buffer, numberOldNote);
			break;
		}
		case 5:
		{
			saveNewNote(buffer, numberOldNote, numberNewNote);
			break;
		}
		}
	}
}

