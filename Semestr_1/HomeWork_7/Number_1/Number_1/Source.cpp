#include "InteractiveWindow.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!test())
	{
		cout << "Тест не пройден\n";
		return 1;
	}
	
	auto tree = createBST();
	interactiveWindows(tree);

	deleteBST(tree);
	return 0;
}