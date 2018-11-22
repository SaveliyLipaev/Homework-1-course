#include "infixToPostfixTranslation.h"

using namespace std;

bool test()
{
	string infStr1 = "(3+6)*(7-8+9)/8+9";
	string infStr2 = "((7-9)+9+(8-9))*(8-6)";
	string infStr3 = "(9-3*3+2*(3-1))*7";
	string postStr1 = infixToPostfix(infStr1);
	string postStr2 = infixToPostfix(infStr2);
	string postStr3 = infixToPostfix(infStr3);
	

	return postStr1 == "36+78-9+*8/9+" && postStr2 == "79-9+89-+86-*" && postStr3 == "933*-231-*+7*";
}