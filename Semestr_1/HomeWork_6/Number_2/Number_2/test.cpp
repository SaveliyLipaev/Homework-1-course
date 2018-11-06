#include "FunctionFor6.2.h"

bool test()
{
	string str1 = "{{()[]}}";
	string str2 = "(({})(";
	string str3 = "){}[]";
	return balanceCheck(str1) && !balanceCheck(str2) && !balanceCheck(str3);
}