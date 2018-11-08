#pragma once

#include <string>
#include <iostream>
#include "HomeWork_6/Stack.h"

using namespace std;

//function returns true if the character was an operator
bool isOperator(const char &symbol);

//function returns true if the character was an number
bool isNumber(const char &symbol);

//determines the priority of the operation, if it is "+" or "-" it returns 1, if "*" or "/" it returns 2
int operandPriority(const char &operand);

//function rewriting infix in postfix
void infixToPostfix(const string &infix, string &postfix);

//a function that returns true if the function passed the test
bool test();