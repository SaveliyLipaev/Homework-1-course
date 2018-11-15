#include "AVL_tree.h"

struct TreeNode
{
	int key = 0;
	string str = "\0";
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

int height(TreeNode *node)
{
	return node ? node->height : 0;
}

int heightDifference(TreeNode *node)
{
	return height(node->rightchild) - height(node->leftchild);
}

bool isEmpty(AvlTree *tree)
{
	return tree->head == nullptr;
}

void newHeight(TreeNode *node)
{
	int heightLeft = height(node->leftchild);
	int heightRight = height(node->rightchild);
	node->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

TreeNode* rightTurn(TreeNode *node)
{
	auto temp = node->leftchild;
	node->leftchild = temp->rightchild;
	temp->rightchild = node;
	newHeight(node);
	newHeight(temp);
	return temp;
}

TreeNode* leftTurn(TreeNode *node)
{
	auto temp = node->rightchild;
	node->rightchild = temp->leftchild;
	temp->leftchild = node;
	newHeight(node);
	newHeight(temp);
	return temp;
}

TreeNode* balance(TreeNode *node)
{
	newHeight(node);

	if (heightDifference(node) == 2)
	{
		if (heightDifference(node->rightchild) < 0)
		{
			node->rightchild = rightTurn(node->rightchild);
		}
		return leftTurn(node);
	}

	if (heightDifference(node) == -2)
	{
		if (heightDifference(node->leftchild) > 0)
		{
			node->leftchild = leftTurn(node->leftchild);
		}
		return rightTurn(node);
	}

	return node;
}

void push(AvlTree *tree, int key, string str)
{
	if (isEmpty(tree))
	{
		tree->head = new TreeNode{ key, str };
	}
	else
	{
		doPush(tree->head, key, str);
	}
}

TreeNode* doPush(TreeNode *node, int key, string str)
{
	if (node->key == key)
	{
		node->str = str;
		return node;
	}
	else if (node == nullptr)
	{
		return node = new TreeNode{ key,str };
	}
	else if (key > node->key)
	{
		node->rightchild = doPush(node->rightchild, key, str);
	}
	else
	{
		node->leftchild = doPush(node->leftchild, key, str);
	}
	return balance(node);
}

void deleteNode(AvlTree *tree, int key)
{
	if (isEmpty(tree))
	{
		return;
	}
	doDeleteNode(tree->head, key);
}

void doDeleteNode(TreeNode *node, int key)
{



}