#pragma once

#include <string>

struct List;
List* createList();
void push(List *list, const std::string name, const std::string number);
void deleteList(List *list);
void mergeSort(List *list, const bool byName);
void printList(List *list);