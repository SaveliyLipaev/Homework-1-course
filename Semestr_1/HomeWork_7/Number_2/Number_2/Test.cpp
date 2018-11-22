#include "TreeParseArithmyExpression.h"
#include <string>

bool test()
{
	std::string testStr1 = "(*(+22)(*22))";
	std::string testStr2 = "(*(+11)2)";
	std::string testStr3 = "(+(*(+22)(*22))(*(+11)2))";
	
	return resultArithmyExpression(testStr1) == 16 && resultArithmyExpression(testStr2) == 4 && resultArithmyExpression(testStr3) == 20;
}