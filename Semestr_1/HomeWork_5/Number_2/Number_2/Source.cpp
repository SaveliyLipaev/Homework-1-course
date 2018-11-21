#include <iostream>
#include "cyclicList.h"
#include "test.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	if (test())
	{
		cout << "Тест пройден!\n\n";
	}
	else
	{
		cout << "Тест не пройден!\n\n";
	}

	auto list = createCyclicList();
	int warriors = 0;
	int step = 0;

	cout << "Введите количество воинов\n";
	cin >> warriors;
	cout << "Введите каждого какого воина убивают\n";
	cin >> step;
	
	for (int i = warriors; i >= 1; --i)
	{
		push(list, i);
	}

	cout << "Останется воин, который стоял на " << deleteWithStep(list, step) << "-ой позиции" << endl;

	deleteList(list);
	return 0;
}