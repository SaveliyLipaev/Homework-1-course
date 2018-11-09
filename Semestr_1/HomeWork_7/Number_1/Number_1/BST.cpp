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

void add(BST *tree, int data)
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
	if (data > node->data)
	{
		if (node->rightChild == nullptr)
		{
			node->rightChild = new NodeBST{ data };
			return;
		}
		addNode(node->rightChild, data);
	}
	else
	{
		if (node->leftChild == nullptr)
		{
			node->leftChild = new NodeBST{ data };
			return;
		}
		addNode(node->leftChild, data);
	}
}

NodeBST* find(BST *tree, int data)
{
	if (isEmpty(tree))
	{
		return nullptr;
	}
	return doFind(tree->head, data);
}

NodeBST* doFind(NodeBST *node, int data)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	else if (node->data == data)
	{
		return node;
	}
	else if (node->data > data)
	{
		return doFind(node->leftChild, data);
	}
	else
	{
		return doFind(node->rightChild, data);
	}
}

NodeBST* findMin(BST *tree)
{
	if (isEmpty(tree))
	{
		return nullptr;
	}
	else
	{
		return doFindMin(tree->head);
	}
}

NodeBST* doFindMin(NodeBST *node)
{
	if (node->leftChild != nullptr)
	{
		return doFindMin(node->leftChild);
	}
	return node;
}

void printDecreasing(BST *tree)
{
	if (isEmpty(tree))
	{
		return;
	}
	else
	{
		doPrintDecreasing(tree->head);
	}
}

void doPrintDecreasing(NodeBST *node)
{
	if (node->rightChild != nullptr)
	{
		doPrintDecreasing(node->rightChild);
	}
	cout << node->data << endl;
	if (node->leftChild != nullptr)
	{
		doPrintDecreasing(node->leftChild);
	}
}

void printIncreasing(BST *tree)
{
	if (isEmpty(tree))
	{
		return;
	}
	else
	{
		doPrintIncreasing(tree->head);
	}
}

void doPrintIncreasing(NodeBST *tree)
{
	if (tree->leftChild != nullptr)
	{
		doPrintIncreasing(tree->leftChild);
	}
	cout << tree->data << endl;
	if (tree->rightChild != nullptr)
	{
		doPrintIncreasing(tree->rightChild);
	}
}

void deleteNode(BST *tree, int data)
{
	auto deleteThis = find(tree, data);
	if (deleteThis == nullptr)
	{
		return;
	}
	doDeleteNode(deleteThis);
}

void doDeleteNode(NodeBST *node)
{
	if (node->leftChild == nullptr)
	{
		auto temp = node->rightChild;
		delete node;
		node = temp;
	}
	else if (node->rightChild == nullptr)
	{
		auto temp = node->leftChild;
		delete node;
		node = temp;
	}
	else
	{
		auto min = node->rightChild;
		auto parentMin = node;
		while (min->leftChild != nullptr)
		{
			parentMin = min;
			min = min->leftChild;
		}
		(parentMin->leftChild == min ? parentMin->leftChild : parentMin->rightChild) = min->rightChild;
		node->data = min->data;
		delete min;
	}
}












