#pragma once
#include <string>

struct Set;
void constructor(Set &set);
unsigned long long hashFunction(const std::string &str);
void add(Set &set, const std::string str);
Set* createSet();
void printTable(Set &set);
float loadFactor(Set &set, int amountOfElements);