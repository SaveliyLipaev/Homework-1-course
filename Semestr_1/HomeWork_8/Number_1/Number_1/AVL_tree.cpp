#include "AVL_tree.h"

using namespace std;

struct TreeNode
{
	int key = 0;
	string str{};
	int height = 0;
	TreeNode *leftchild = nullptr;
	TreeNode *rightchild = nullptr;
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
	return height(node->rightchild) - height(node->leftchild);
}

bool isEmpty(const AvlTree *tree)
{
	return tree->head == nullptr;
}

void newHeight(TreeNode *node)
{
	int heightLeft = height(node->leftchild);
	int heightRight = height(node->rightchild);
	node->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

TreeNode* rightTurn(TreeNode *node, AvlTree *tree)
{
	if (node == tree->head)
	{
		tree->head = node->leftchild;
	}
	auto temp = node->leftchild;
	node->leftchild = temp->rightchild;
	temp->rightchild = node;
	newHeight(node);
	newHeight(temp);
	return temp;
}

TreeNode* leftTurn(TreeNode *node, AvlTree *tree)
{
	if (node == tree->head)
	{
		tree->head = node->rightchild;
	}
	auto temp = node->rightchild;
	node->rightchild = temp->leftchild;
	temp->leftchild = node;
	newHeight(node);
	newHeight(temp);
	return temp;
}

TreeNode* balance(TreeNode *node, AvlTree *tree)
{
	newHeight(node);

	if (heightDifference(node) == 2)
	{
		if (heightDifference(node->rightchild) < 0)
		{
			node->rightchild = rightTurn(node->rightchild, tree);
		}
		return leftTurn(node, tree);
	}

	if (heightDifference(node) == -2)
	{
		if (heightDifference(node->leftchild) > 0)
		{
			node->leftchild = leftTurn(node->leftchild, tree);
		}
		return rightTurn(node, tree);
	}

	return node;
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

TreeNode* doPush(TreeNode *node, AvlTree *tree, const int key, const string str)
{
	if (node == nullptr)
	{
		return node = new TreeNode{ key,str };
	}
	else if (node->key == key)
	{
		node->str = str;
		return node;
	}
	else if (key > node->key)
	{
		node->rightchild = doPush(node->rightchild, tree, key, str);
	}
	else
	{
		node->leftchild = doPush(node->leftchild, tree, key, str);
	}
	return balance(node, tree);
}

void deleteNode(AvlTree *tree, const int key)
{
	if (isEmpty(tree))
	{
		return;
	}
	tree->head=doDeleteNode(tree->head, tree, key);
}

TreeNode* doDeleteNode(TreeNode *node, AvlTree *tree, const int key)
{
	if (node == nullptr)
	{
		return 0;
	}
	else if (key > node->key)
	{
		node->rightchild = doDeleteNode(node->rightchild, tree, key);
	}
	else if (key < node->key)
	{
		node->leftchild = doDeleteNode(node->leftchild, tree, key);
	}
	else
	{
		if (node->rightchild == nullptr)  //≈сли у узла нет правого ребенка, тогда возвращаем левого и удал€ем узел
		{
			auto temp = node->leftchild;
			delete node;
			return temp;
		}
		else  //≈сли есть правый ребенок 
		{
			auto right = node->rightchild;
			auto left = node->leftchild;
			auto min = node->rightchild;
			auto parentMin = node;
			while (min->leftchild != nullptr)
			{
				parentMin = min;
				min = min->leftchild;
			}
			if (node->rightchild == min) //если минимальный элемент это и есть правый ребенок узла который надо удалить
			{
				min->leftchild = left;
				delete node;
				return balance(min, tree);
			}
			else // если минимальный элемент это какой либо другой элемент
			{
				parentMin->leftchild = min->rightchild;
				min->leftchild = left;
				min->rightchild = right;
				delete node;
				return balance(min, tree);
			}
		}
	}
	return balance(node, tree);
}

string takingString(const AvlTree *tree, const int key)
{
	return doTakingString(tree->head, key);
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
		return doTakingString(node->rightchild, key);
	}
	else
	{
		return doTakingString(node->leftchild, key);
	}
}

bool elementIsPresent(const AvlTree *tree, const int key)
{
	return doElementIsPresent(tree->head, key);
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
		return doElementIsPresent(node->rightchild, key);
	}
	else
	{
		return doElementIsPresent(node->leftchild, key);
	}
}

void deleteTree(AvlTree *tree)
{
	if (tree->head != nullptr)
	{
		deleteSubtree(tree->head);
	}
	delete tree;
}

void deleteSubtree(TreeNode *node)
{
	if (node->rightchild != nullptr)
	{
		deleteSubtree(node->rightchild);
	}

	if (node->leftchild != nullptr)
	{
		deleteSubtree(node->leftchild);
	}

	delete node;
}