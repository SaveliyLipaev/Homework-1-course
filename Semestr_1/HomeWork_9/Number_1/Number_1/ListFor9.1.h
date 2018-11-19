#pragma once
#include <string>

struct NodeList;
struct List;

//A function that returns a pointer to the allocated memory for the List type
List *createList();

//returns the address of the found node if not found returns nullptr
NodeList* findNode(List *&list, const std::string str);

//The function returns true if the list is empty
bool isEmpty(List *list);

//Function that adds an item to the list
void push(List *list, const std::string str);

//The function that removes an item in the list that the head points to.
//and returns the data of this item.
void pop(List *list);

//The function that clears the memory that occupied the list
void deleteList(List *list);

//prints List values
void printlist(List *list);

//increases parameter quantity by one
void increaseQuantity(NodeList *list);

//returns list length
int lengthList(List *list);

//returns parameter quantity for node
int returnQuantity(NodeList *node);