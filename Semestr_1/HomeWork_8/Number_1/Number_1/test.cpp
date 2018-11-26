#include "AVL_tree.h"


bool test()
{
	auto tree = createAvlTree();

	for (int i = -2; i <= 2; ++i)
	{
		push(tree, i, "");
	}
	push(tree, 150, "150");
	push(tree, 125, "125");
	push(tree, 100, "100");

	for (int i = -2; i <= 2; ++i)
	{
		if (!elementIsPresent(tree, i))
		{
			deleteTree(tree);
			return false;
		}
	}
	if (!elementIsPresent(tree, 125) || !elementIsPresent(tree, 100) || !elementIsPresent(tree, 150) || elementIsPresent(tree, 53))
	{
		deleteTree(tree);
		return false;
	}

	deleteNode(tree, 150);
	if (elementIsPresent(tree, 150))
	{
		deleteTree(tree);
		return false;
	}
	for (int i = -2; i <= 2; ++i)
	{
		deleteNode(tree, i);
		if (elementIsPresent(tree, i))
		{
			deleteTree(tree);
			return false;
		}
	}

	if (takingString(tree, 125) != "125" || takingString(tree, 100) != "100" || takingString(tree, 150) != "")
	{
		deleteTree(tree);
		return false;
	}
	deleteNode(tree, 125);
	deleteNode(tree, 100);

	if (!isEmpty(tree))
	{
		deleteTree(tree);
		return false;
	}
	deleteTree(tree);
	return true;
}
