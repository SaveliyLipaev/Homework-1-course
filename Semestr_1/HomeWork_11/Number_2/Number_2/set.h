#pragma once

struct Sets;
Sets* createSets(const int newSize);
void makeSet(Sets *set, const int number);
int find(Sets *set, const int number);
void unionSet(Sets *set, const int firstNumber, const int secondNumber);