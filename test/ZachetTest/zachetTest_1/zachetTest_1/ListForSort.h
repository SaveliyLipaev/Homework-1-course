#pragma once

#include <string>

struct List;
struct ListNode;

//returns the address of the selected memory cell for the List structure
List* createList();

//return true if list pustoy
bool isEmpty(List *list);

//Adds an item to the top of the list
void push(List *list, const std::string str);

//Removes the entire list
void deleteList(List *list);

//Sorts the list, true if needed by name, false if needed by number
void mergeSort(List *list);

//prints a list
void printListInFile(List *list, std::ofstream &file);

ListNode* findNode(List *&list, const std::string &str);