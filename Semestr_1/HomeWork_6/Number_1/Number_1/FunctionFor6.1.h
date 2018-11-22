#pragma once

#include <string>

//The function returns true if the char is a character from 0..9
bool isNumber(const char &symbol);

//The function returns true if the char is a character "+,-,*,/"
bool isOperator(const char &symbol);

//the function returns the number that was obtained as a result of the operation
int operation(const char &symbol, const int &operandOne, const int &operandTwo);

//the function returns the value calculated by the arithmetic expression in the postfix form
int expressionResult(const std::string &str);

//the function returns true if the test passed
bool test();