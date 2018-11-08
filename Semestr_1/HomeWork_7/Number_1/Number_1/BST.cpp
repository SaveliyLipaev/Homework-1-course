#include <iostream>
#include "BST.h"
using namespace std;

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

BST *createBST()
{
	return new BST;
}

bool isEmpty(BST *tree)
{
	return tree->head == nullptr;
}

void addNodeBST(BST *tree, int data)
{
	if (isEmpty(tree))
	{
		tree->head = new NodeBST{ data };
	}
	else
	{
		addNode(tree->head, data);
	}
}

void addNode(NodeBST *node, int data)
{
	if (node == nullptr)
	{
		node = new NodeBST{ data };
	}
	else if (data > node->data)
	{
		addNode(node->rightChild, data);
	}
	else
	{
		addNode(node->leftChild, data);
	}
}

void printDecreasingBST(BST *tree)
{
	if (isEmpty(tree))
	{
		return;
	}
	else
	{
		printDecreasingTree(tree->head);
	}
}

void printDecreasingTree(NodeBST *node)
{
	if (node->rightChild != nullptr)
	{
		printDecreasingTree(node->rightChild);
	}
	cout << node->data << endl;
	if (node->leftChild != nullptr)
	{
		printDecreasingTree(node->leftChild);
	}
}

void printIncreasingBST(BST *tree)
{
	if (isEmpty(tree))
	{
		return;
	}
	else
	{
		printIncreasingTree(tree->head);
	}
}

void printIncreasingTree(NodeBST *tree)
{
	if (tree->leftChild != nullptr)
	{
		printDecreasingTree(tree->leftChild);
	}
	cout << tree->data << endl;
	if (tree->rightChild != nullptr)
	{
		printDecreasingTree(tree->rightChild);
	}
}
















