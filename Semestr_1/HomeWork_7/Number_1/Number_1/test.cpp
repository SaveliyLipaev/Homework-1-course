#include "InteractiveWindow.h"

struct BST
{
	NodeBST *head = nullptr;
};

struct NodeBST
{
	int data;
	NodeBST *leftChild = nullptr;
	NodeBST *rightChild = nullptr;
};

bool test()
{
	auto tree = createBST();

	add(tree, 50);
	add(tree, 100);
	if (tree->head->data != 50 || tree->head->rightChild->data != 100)
	{
		return false;
	}
	add(tree, 25);
	add(tree, 35);
	if (tree->head->leftChild->data != 25 || tree->head->leftChild->rightChild->data != 35)
	{
		return false;
	}
	if (!find(tree, 25) || !find(tree, 100) || find(tree, 10))
	{
		return false;
	}
	terriblyUglyDeleteNode(tree, 25);
	if (tree->head->leftChild->data == 25 || tree->head->leftChild->data != 35)
	{
		return false;
	}
	terriblyUglyDeleteNode(tree, 100);
	terriblyUglyDeleteNode(tree, 50);
	terriblyUglyDeleteNode(tree, 35);
	if (!isEmpty(tree))
	{
		return false;
	}
	deleteBST(tree);
	return true;
}