#pragma once

struct List;

//return true if list is symmetry
bool thisListSymmetry(List *list);

//returns the address of the selected memory cell for the List structure
List* createList();

//return true if list pustoy
bool isEmpty(List *list);

//Adds an item to the top of the list
void push(List *list, const int data);

//Removes the entire list
void deleteList(List *list);

//print list
void printList(List *list);