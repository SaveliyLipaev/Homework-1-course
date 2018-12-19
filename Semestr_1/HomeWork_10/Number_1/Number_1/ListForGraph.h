#pragma once

struct List;

//A function that returns a pointer to the allocated memory for the List type
List *createList();

//The function returns true if the list is empty
bool isEmpty(List *list);

//Function that adds an item to the list
void push(List *list, const int &node, const int &length);

//The function that removes an item in the list that the head points to
//and returns the data of this item.
void pop(List *list);

//The function that clears the memory that occupied the list
void deleteList(List *list);

//The function return length by list
int lengthList(List *list);

//the function returns the i-th vertex with which the given vertex is connected
int returnNode(List *list, const int &number);

//the function returns the i - th arc length with which the given vertex is connected
int returnLengthArc(List *list, const int &number);