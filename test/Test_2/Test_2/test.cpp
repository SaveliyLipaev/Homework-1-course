#include <vector>
#include "ListForTask.h"

using namespace std;

void pushInList(List *list, vector<int> mas)
{
	for (size_t i = 0; i < mas.size(); ++i)
	{
		push(list, mas[i]);
	}
}

bool resultTest2(List *list1, List *list2, List *list3)
{
	return thisListSymmetry(list1) && !thisListSymmetry(list2) && thisListSymmetry(list3);
}

bool testForTask2()
{
	vector<int> MasForTest1{ 1, 2, 3, 2, 1 };
	vector<int> MasForTest2{ 1, 2, 3, 4, 2, 1 };
	vector<int> MasForTest3{ 1, 2, 3, 2, 1, 1, 2, 3, 2, 1 };
	auto listForTest1 = createList();
	auto listForTest2 = createList();
	auto listForTest3 = createList();
	pushInList(listForTest1, MasForTest1);
	pushInList(listForTest2, MasForTest2);
	pushInList(listForTest3, MasForTest3);

	bool temp = resultTest2(listForTest1, listForTest2, listForTest3);

	deleteList(listForTest1);
	deleteList(listForTest2);
	deleteList(listForTest3);

	return temp;
}