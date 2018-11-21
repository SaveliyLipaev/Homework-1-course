#pragma once

#include <string>

struct List;

//returns the address of the selected memory cell for the List structure
List* createList();

//return true if list pustoy
bool isEmpty(List *list);

//Adds an item to the top of the list
void push(List *list, const std::string name, const std::string number);

//Removes the entire list
void deleteList(List *list);

//Sorts the list, true if needed by name, false if needed by number
void mergeSort(List *list, const bool byName);

//prints a list
void printList(List *list);

//return true if list sorting by name
bool checkSortByName(List *list);

//return true if list sorting by number
bool checkSortByNumber(List *list);