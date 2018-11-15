#include "cyclicList.h"

int forTesting(const int warriors, const int step)
{
	auto list = createCyclicList();
	for (int i = warriors; i >= 1; --i)
	{
		push(list, i);
	}
	int temp = deleteWithStep(list, step);
	deleteList(list);
	return temp;
}

bool test()
{
	return forTesting(5, 3) == 4 && forTesting(8, 5) == 3 && forTesting(10, 2) == 5;
}