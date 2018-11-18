#include "infixToPostfixTranslation.h"
#include "HomeWork_6/Stack.h"
#include <string>

using namespace std;

bool isOperator(const char &symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

bool isNumber(const char &symbol)
{
	return symbol >= '0' && symbol <= '9';
}

string infixToPostfix(const string &infix)
{
	string postfix{};
	auto stack = createStack();
	const int length = (int)infix.size();

	for (int i = 0; i < length; ++i)
	{
		if (isNumber(infix[i]))
		{
			postfix += infix[i];
		}
		else if (isOperator(infix[i]))
		{
			while (!isEmpty(stack) && isOperator(lastValue(stack)) && operandPriority(lastValue(stack)) >= operandPriority(infix[i]))
			{
				postfix += pop(stack);
			}
			push(stack, infix[i]);
		}
		else if (infix[i] == '(')
		{
			push(stack, infix[i]);
		}
		else if (infix[i] == ')')
		{
			while (lastValue(stack) != '(')
			{
				postfix += pop(stack);
			}
			pop(stack);
		}
	}
	while (!isEmpty(stack))
	{
		postfix += pop(stack);
	}
	deleteStack(stack);
	return postfix;
}

int operandPriority(const char &operand)
{
	switch (operand)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default: 
		return 0;
	}
}