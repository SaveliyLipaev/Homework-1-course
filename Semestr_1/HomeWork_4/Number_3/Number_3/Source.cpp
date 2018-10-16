#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <fstream>
#include "Head_MyFuncSem_1.h"

struct contact
{
	char name[30]{};
	int number;
};

void addNote(contact *mas, const int numberOldNote, int &numberNewNote);
void interactiveWindow(void);
void printNote(contact *mas, const int numberOldNote, const int numberNewNote);
void saveNewNote(contact *mas, int &numberOldNote, int &numberNewNote);
void searchName(contact *mas, const int numberOldNote);
void backButton(void);

int main()
{
	setlocale(LC_ALL, "Russian");
	interactiveWindow();
	return 0;
}

void addNote(contact *mas, const int numberOldNote, int &numberNewNote)
{
	system("cls");
	printf("Введите имя\n");
	scanf("%s", &mas[numberOldNote+numberNewNote].name);
	printf("\nВведите номер\n");
	scanf("%d", &mas[numberOldNote + numberNewNote].number);
	++numberNewNote;
}

void interactiveWindow() 
{
	contact buffer[100]{};
	int numberOldNote = 0;
	int numberNewNote = 0;
	FILE *file = fopen("phonebook.txt","r");
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

void printNote(contact *mas,const int numberOldNote, const int numberNewNote)
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

void saveNewNote(contact *mas, int &numberOldNote, int &numberNewNote)
{
	FILE *file = fopen("phonebook.txt", "a");
	for (int i = numberOldNote; i < numberOldNote + numberNewNote; ++i)
	{
		fprintf(file, "%s  -  %d\n", mas[i].name, mas[i].number);
	}
	fclose(file);
	numberOldNote += numberNewNote;
	numberNewNote = 0;
}

void searchName(contact *mas, const int numberOldNote)
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
