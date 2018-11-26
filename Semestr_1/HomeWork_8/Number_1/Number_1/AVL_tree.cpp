#include "AVL_tree.h"

using namespace std;

struct TreeNode
{
	int key = 0;
	string str{};
	int height = 0;
	TreeNode *leftChild = nullptr;
	TreeNode *rightChild = nullptr;
};

struct AvlTree
{
	TreeNode *head = nullptr;
};

AvlTree* createAvlTree()
{
	return new AvlTree;
}

int height(const TreeNode *node)
{
	if (node == nullptr)
	{
		return 0;
	}
	return node->height;
}

int heightDifference(const TreeNode *node)
{
	return height(node->rightChild) - height(node->leftChild);
}

bool isEmpty(const AvlTree *tree)
{
	return tree->head == nullptr;
}

void newHeight(TreeNode *node)
{
	int heightLeft = height(node->leftChild);
	int heightRight = height(node->rightChild);
	node->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

TreeNode* rightTurn(TreeNode *node, AvlTree *tree)
{
	if (node == tree->head)
	{
		tree->head = node->leftChild;
	}
	auto temp = node->leftChild;
	node->leftChild = temp->rightChild;
	temp->rightChild = node;
	newHeight(node);
	newHeight(temp);
	return temp;
}

TreeNode* leftTurn(TreeNode *node, AvlTree *tree)
{
	if (node == tree->head)
	{
		tree->head = node->rightChild;
	}
	auto temp = node->rightChild;
	node->rightChild = temp->leftChild;
	temp->leftChild = node;
	newHeight(node);
	newHeight(temp);
	return temp;
}

TreeNode* balance(TreeNode *node, AvlTree *tree)
{
	newHeight(node);

	if (heightDifference(node) == 2)
	{
		if (heightDifference(node->rightChild) < 0)
		{
			node->rightChild = rightTurn(node->rightChild, tree);
		}
		return leftTurn(node, tree);
	}

	if (heightDifference(node) == -2)
	{
		if (heightDifference(node->leftChild) > 0)
		{
			node->leftChild = leftTurn(node->leftChild, tree);
		}
		return rightTurn(node, tree);
	}

	return node;
}

TreeNode* doPush(TreeNode *node, AvlTree *tree, const int key, const string str)
{
	if (node == nullptr)
	{
		return new TreeNode{ key, str };
	}
	else if (node->key == key)
	{
		node->str = str;
		return node;
	}
	else if (key > node->key)
	{
		node->rightChild = doPush(node->rightChild, tree, key, str);
	}
	else
	{
		node->leftChild = doPush(node->leftChild, tree, key, str);
	}
	return balance(node, tree);
}

void push(AvlTree *tree, const int key, const string str)
{
	if (isEmpty(tree))
	{
		tree->head = new TreeNode{ key, str };
	}
	else
	{
		doPush(tree->head, tree, key, str);
	}
}

TreeNode* doDeleteNode(TreeNode *node, AvlTree *tree, const int key)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	else if (key > node->key)
	{
		node->rightChild = doDeleteNode(node->rightChild, tree, key);
	}
	else if (key < node->key)
	{
		node->leftChild = doDeleteNode(node->leftChild, tree, key);
	}
	else
	{
		if (node->rightChild == nullptr)  //≈сли у узла нет правого ребенка, тогда возвращаем левого и удал€ем узел
		{
			auto temp = node->leftChild;
			delete node;
			return temp;
		}
		else  //≈сли есть правый ребенок 
		{
			auto right = node->rightChild;
			auto left = node->leftChild;
			auto min = node->rightChild;
			auto parentMin = node;
			while (min->leftChild != nullptr)
			{
				parentMin = min;
				min = min->leftChild;
			}
			if (node->rightChild == min) //если минимальный элемент это и есть правый ребенок узла который надо удалить
			{
				min->leftChild = left;
				delete node;
				return balance(min, tree);
			}
			else // если минимальный элемент это какой либо другой элемент
			{
				parentMin->leftChild = min->rightChild;
				min->leftChild = left;
				min->rightChild = right;
				delete node;
				return balance(min, tree);
			}
		}
	}
	return balance(node, tree);
}

void deleteNode(AvlTree *tree, const int key)
{
	if (isEmpty(tree))
	{
		return;
	}
	tree->head = doDeleteNode(tree->head, tree, key);
}

string doTakingString(const TreeNode *node, const int key)
{

	if (node == nullptr)
	{
		return "";
	}
	else if (node->key == key)
	{
		return node->str;
	}
	else if (key > node->key)
	{
		return doTakingString(node->rightChild, key);
	}
	else
	{
		return doTakingString(node->leftChild, key);
	}
}

string takingString(const AvlTree *tree, const int key)
{
	return doTakingString(tree->head, key);
}

bool doElementIsPresent(const TreeNode *node, const int key)
{
	if (node == nullptr)
	{
		return false;
	}
	else if (node->key == key)
	{
		return true;
	}
	else if (key > node->key)
	{
		return doElementIsPresent(node->rightChild, key);
	}
	else
	{
		return doElementIsPresent(node->leftChild, key);
	}
}

bool elementIsPresent(const AvlTree *tree, const int key)
{
	return doElementIsPresent(tree->head, key);
}

void deleteSubtree(TreeNode *node)
{
	if (node->rightChild != nullptr)
	{
		deleteSubtree(node->rightChild);
	}

	if (node->leftChild != nullptr)
	{
		deleteSubtree(node->leftChild);
	}

	delete node;
}

void deleteTree(AvlTree *tree)
{
	if (tree->head != nullptr)
	{
		deleteSubtree(tree->head);
	}
	delete tree;
}