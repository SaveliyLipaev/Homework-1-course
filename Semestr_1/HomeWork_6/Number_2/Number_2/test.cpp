#include "FunctionFor6.2.h"

bool test()
{
	std::string str1 = "{{()[]}}";
	std::string str2 = "(({})(";
	std::string str3 = "){}[]";
	return balanceCheck(str1) && !balanceCheck(str2) && !balanceCheck(str3);
}