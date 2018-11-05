#include "FunctionFor6.1.h"
#include "HomeWork_6/Stack.h"


int operation(const char &symbol, const int &operandOne, const int &operandTwo)
{
	int result = 0;
	switch (symbol)
	{
	case '+':
	{
		result = operandOne + operandTwo;
		break;
	}
	case '-':
	{
		result = operandOne - operandTwo;
		break;
	}
	case '*':
	{
		result = operandOne * operandTwo;
		break;
	}
	case '/':
	{
		result = operandOne / operandTwo;
		break;
	}
	}
	return result;
}

bool isNumber(const char &symbol)
{
	return symbol >= '0' && symbol <= '9';
}

bool isOperator(const char &symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

int expressionResult(const string &str)
{
	auto stack = createStack();
	const int length = (int)str.size();

	for (int i = 0; i < length; ++i)
	{
		if (isNumber(str[i]))
		{
			push(stack, (int)(str[i] - 48));
		}
		else if (isOperator(str[i]))
		{
			const int operandTwo = pop(stack);
			const int operandOne = pop(stack);
			push(stack, operation(str[i], operandOne, operandTwo));
		}
	}
	int result = pop(stack);
	deleteStack(stack);
	return result;
}
