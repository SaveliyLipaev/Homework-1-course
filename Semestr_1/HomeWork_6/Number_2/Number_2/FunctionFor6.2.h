#pragma once

#include <string>
#include <iostream>

using namespace std;

//returns true if opening bracket
bool isOpeningBracket(const char &symbol);

//returns true if closing bracket
bool isClosingBracket(const char &symbol);

//returns true if family bracket
bool isFamilyBracket(const char &symbol1, const char &symbol2);

//the function returns true if the balance of brackets is met
bool balanceCheck(string &str);

//the function returns true if the program has passed testing
bool test();