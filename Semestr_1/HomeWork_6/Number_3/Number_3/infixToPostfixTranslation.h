#pragma once

#include <string>


//function returns true if the character was an operator
bool isOperator(const char &symbol);

//function returns true if the character was an number
bool isNumber(const char &symbol);

//determines the priority of the operation, if it is "+" or "-" it returns 1, if "*" or "/" it returns 2
int operandPriority(const char &operand);

//function rewriting infix in postfix
std::string infixToPostfix(const std::string &infix);

//a function that returns true if the function passed the test
bool test();