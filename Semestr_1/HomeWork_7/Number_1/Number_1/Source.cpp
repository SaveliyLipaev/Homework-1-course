#include "InteractiveWindow.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	auto tree = createBST();
	interactiveWindows(tree);

	deleteBST(tree);
	return 0;
}