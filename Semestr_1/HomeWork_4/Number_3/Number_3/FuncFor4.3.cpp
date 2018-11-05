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
	printf("0 - Назад\n");
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
	printf("0 - Назад\n");
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
	printf("Поиск имени по телефону \nВведите номер телефона\n");
	int number = 0;
	scanf("%d", &number);
	for (int i = 0; i < numberOldNote; ++i)
	{
		if (mas[i].number == number)
		{
			printf("Хозяин этого телефона: %s\n", mas[i].name);
			backButton();
			return;
		}
	}
	printf("Человека с таким номером не найдено!\n");
	backButton();
}

void searchNumber(Contact *mas, const int numberOldNote)
{
	system("cls");
	printf("Поиск телефона по имени \nВведите имя\n");
	char name[40]{};
	scanf("%s", name);
	for (int i = 0; i < numberOldNote; ++i)
	{
		if (!strcmp(mas[i].name, name))
		{
			printf("Телефон этого человека: %d\n", mas[i].number);
			backButton();
			return;
		}
	}
	printf("Номер этого чеоловека не найден!\n");
	backButton();
}

void addNote(Contact *mas, const int numberOldNote, int &numberNewNote)
{
	system("cls");
	printf("Введите имя\n");
	scanf("%s", &mas[numberOldNote + numberNewNote].name);
	printf("\nВведите номер\n");
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
		printf("Новая база!\n");
	}

	while (fscanf(file, "%s%d", &buffer[numberOldNote].name, &buffer[numberOldNote].number) != EOF)
	{
		++numberOldNote;
	}
	fclose(file);
	while (true)
	{
		system("cls");
		printf("0 - выйти\n1 - добавить запись\n2 - распечатать все имеющиеся записи\n3 - найти телефон по имение\n4 - найти имя по телефону\n5 - сохранить текущие данные в файл\n");
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

