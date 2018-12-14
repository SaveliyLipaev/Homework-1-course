#include <iostream>
#include <clocale>
#include "sortedList.h"
#include "InteractiveWindow.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	if (test())
	{
		SortedList* list = createdSortedList();

		interactiveWindows(list);

		deleteList(list);
		delete list;
	}
	else
	{
		cout << "Тест не пройден!!\n";
	}
	return 0;
}