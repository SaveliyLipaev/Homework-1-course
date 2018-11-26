#include "InteractiveWindow.h"
#include "BST.h"
#include <iostream>


struct NodeBST
{
	int data;
	NodeBST *leftChild = nullptr;
	NodeBST *rightChild = nullptr;
};

struct BST
{
	NodeBST *head = nullptr;
};

BST *createBST()
{
	return new BST;
}

bool isEmpty(BST *tree)
{
	return tree->head == nullptr;
}

void addNode(NodeBST *node, int data)
{
	if (node->data == data)
	{
		return;
	}
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

bool doFind(NodeBST *node, int data)
{
	if (node == nullptr)
	{
		return false;
	}
	else if (node->data == data)
	{
		return true;
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

bool find(BST *tree, int data)
{
	if (isEmpty(tree))
	{
		return false;
	}
	return doFind(tree->head, data);
}

void doPrintDecreasing(NodeBST *node)
{
	if (node->rightChild != nullptr)
	{
		doPrintDecreasing(node->rightChild);
	}
	std::cout << node->data << std::endl;
	if (node->leftChild != nullptr)
	{
		doPrintDecreasing(node->leftChild);
	}
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

void doPrintIncreasing(NodeBST *tree)
{
	if (tree->leftChild != nullptr)
	{
		doPrintIncreasing(tree->leftChild);
	}
	std::cout << tree->data << std::endl;
	if (tree->rightChild != nullptr)
	{
		doPrintIncreasing(tree->rightChild);
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

void terriblyUglyDeleteNode(BST *tree, int data)
{
	if (tree->head->data == data)
	{
		deleteFirstElement(tree);
	}
	else
	{
		auto parentNode = tree->head;
		auto node = tree->head;

		while (true)
		{
			if (node == nullptr)
			{
				return;
			}
			else if (node->data == data)
			{
				break;
			}
			else if (node->data > data)
			{
				parentNode = node;
				node = node->leftChild;
			}
			else
			{
				parentNode = node;
				node = node->rightChild;
			}
		}
		if (node->leftChild == nullptr)
		{
			if (parentNode->rightChild == node)
			{
				parentNode->rightChild = node->rightChild;
			}
			else
			{
				parentNode->leftChild = node->rightChild;
			}
			delete node;
		}
		else if (node->rightChild == nullptr)
		{
			if (parentNode->rightChild == node)
			{
				parentNode->rightChild = node->leftChild;
			}
			else
			{
				parentNode->leftChild = node->leftChild;
			}
			delete node;
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
}

void doDeleteBST(NodeBST *node)
{
	if (node->leftChild != nullptr)
	{
		doDeleteBST(node->leftChild);
	}

	if (node->rightChild != nullptr)
	{
		doDeleteBST(node->rightChild);
	}

	delete node;
}

void deleteBST(BST *tree)
{
	if (tree->head != nullptr)
	{
		doDeleteBST(tree->head);
	}
	delete tree;
}

void deleteFirstElement(BST *tree)
{
	auto node = tree->head;
	if (node->leftChild == nullptr)
	{
		auto temp = node;
		tree->head = node->rightChild;
		delete temp;
	}
	else if (node->rightChild == nullptr)
	{
		auto temp = node;
		tree->head = node->leftChild;
		delete temp;
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

