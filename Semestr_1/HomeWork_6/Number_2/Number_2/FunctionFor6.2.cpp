#include "FunctionFor6.2.h"
#include "HomeWork_6/Stack.h"

using namespace std;

bool isClosingBracket(const char &symbol)
{
	return symbol == ')' || symbol == '}' || symbol == ']';
}

bool isOpeningBracket(const char &symbol)
{
	return symbol == '(' || symbol == '{' || symbol == '[';
}

bool isFamilyBracket(const char &symbol1, const char &symbol2)
{
	return symbol1 == '(' && symbol2 == ')' || symbol1 == '[' && symbol2 == ']' || symbol1 == '{' && symbol2 == '}';
}

bool balanceCheck(const string &str)
{
	auto stack = createStack();
	const int length = (int)str.size();
	for (int i = 0; i < length; ++i)
	{
		if (isEmpty(stack))
		{
			if (isClosingBracket(str[i]))
			{
				return false;
			}
			else
			{
				push(stack, str[i]);
			}
		}
		else
		{
			if (isFamilyBracket(lastValue(stack), str[i]))
			{
				pop(stack);
			}
			else if (isOpeningBracket(str[i]))
			{
				push(stack, str[i]);
			}
			else
			{
				return false;
			}
		}
	}

	if (isEmpty(stack))
	{
		deleteStack(stack);
		return true;
	}

	deleteStack(stack);
	return false;
}