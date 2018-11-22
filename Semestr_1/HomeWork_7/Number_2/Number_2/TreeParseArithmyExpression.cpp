#include <string>
#include <iostream>

struct TreeNode
{
	char symbol = '\0';
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;
	TreeNode *parent = nullptr;
};

struct Tree
{
	TreeNode *root = nullptr;
};

bool isEmpty(Tree *tree)
{
	return tree->root == nullptr;
}

bool isDigit(const char &symbol)
{
	return symbol >= '0' && symbol <= '9';
}

bool isOperator(const char &symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

Tree* createTree()
{
	return new Tree;
}

void doDeleteTree(TreeNode *node)
{
	if (node->left != nullptr)
	{
		doDeleteTree(node->left);
	}
	if (node->right != nullptr)
	{
		doDeleteTree(node->right);
	}
	delete node;
}

void deleteTree(Tree* tree)
{
	if (isEmpty(tree))
	{
		delete tree;
		return;
	}
	doDeleteTree(tree->root);
}

TreeNode* addLeftChild(TreeNode *node)
{
	auto newElement = new TreeNode{ '\0', nullptr, nullptr, node };
	node->left = newElement;
	return newElement;
}

TreeNode* addRightChild(TreeNode *node)
{
	auto newElement = new TreeNode{ '\0', nullptr, nullptr, node };
	node->right = newElement;
	return newElement;
}

void changeChar(TreeNode *node, const char &symbol)
{
	node->symbol = symbol;
}

TreeNode* goToParent(TreeNode *node)
{
	return node->parent;
}

void expressionInTree(Tree *tree, const std::string &str)
{
	const int length = (int)str.length();
	auto targetElement = new TreeNode{ '\0', nullptr, nullptr, nullptr };

	for (int i = 0; i < length; ++i)
	{
		if (str[i] == '(')
		{
			if (tree->root == nullptr)
			{
				tree->root = targetElement;
			}
			else if (targetElement->left == nullptr)
			{
				targetElement = addLeftChild(targetElement);
			}
			else
			{
				targetElement = addRightChild(targetElement);
			}
		}
		else if (isOperator(str[i]))
		{
			changeChar(targetElement, str[i]);
		}
		else if (isDigit(str[i]))
		{
			if (targetElement->left == nullptr)
			{
				targetElement = addLeftChild(targetElement);
			}
			else
			{
				targetElement = addRightChild(targetElement);
			}
			changeChar(targetElement, str[i]);
			targetElement = goToParent(targetElement);
		}
		else if (str[i] == ')' && goToParent(targetElement) != nullptr)
		{
			targetElement = goToParent(targetElement);
		}
		else
		{
			break;
		}
	}
}

int operation(const char operation, const int operand1, const int operand2)
{
	switch (operation)
	{
	case '+':
	{
		return operand1 + operand2;
	}
	case '-':
	{
		return operand1 - operand2;
	}
	case '*':
	{
		return operand1 * operand2;
	}
	case '/':
	{
		return operand1 / operand2;
	}
	default:
	{
		std::cout << "ÏÐÎÈÇÎØËÀ ÎØÈÁÊÀ Â ÔÓÍÊÖÈÈ int operation(const char operation, const int operand1, const int operand2)\n";
		return 0;
	}
	}
}

int fromCharInInt(const char &symbol)
{
	return (int)(symbol - '0');
}

int doResultArithmyExpression(TreeNode *node)
{
	if (isOperator(node->symbol))
	{
		return operation(node->symbol, doResultArithmyExpression(node->left), doResultArithmyExpression(node->right));
	}
	else
	{
		return fromCharInInt(node->symbol);
	}
}

int resultArithmyExpression(const std::string str)
{
	auto tree = createTree();
	expressionInTree(tree, str);
	int result= doResultArithmyExpression(tree->root);
	deleteTree(tree);
	return result;
}