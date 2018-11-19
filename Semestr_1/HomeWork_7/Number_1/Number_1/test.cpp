#include "InteractiveWindow.h"

bool test()
{
	auto tree = createBST();

	add(tree, 50);
	add(tree, 100);
	if (!find(tree, 50) || !find(tree, 100) || isEmpty(tree))
	{
		deleteBST(tree);
		return false;
	}
	add(tree, 25);
	terriblyUglyDeleteNode(tree, 50);
	if (find(tree, 50))
	{
		deleteBST(tree);
		return false;
	}
	terriblyUglyDeleteNode(tree, 100);
	terriblyUglyDeleteNode(tree, 25);
	if (!isEmpty(tree))
	{
		deleteBST(tree);
		return false;
	}
	deleteBST(tree);
	return true;
}