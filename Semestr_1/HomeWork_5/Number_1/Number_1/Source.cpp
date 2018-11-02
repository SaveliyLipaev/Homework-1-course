#include <iostream>
#include "sortedList.h"
#include "InteractiveWindow.h"

using namespace std;

int main()
{
	SortedList* list = createdSortedList();
	setlocale(LC_ALL, "Russian");

	interactiveWindows(list);
	
	deleteList(list);
	return 0;
}