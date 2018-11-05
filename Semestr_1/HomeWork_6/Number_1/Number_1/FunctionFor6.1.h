#pragma once

#include <iostream>
#include <string>

using namespace std;

bool isNumber(const char &symbol);
bool isOperator(const char &symbol);
int operation(const char &symbol, const int &operandOne, const int &operandTwo);
int expressionResult(const string &str);