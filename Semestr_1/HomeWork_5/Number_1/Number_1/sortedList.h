#pragma once


struct SortedList;
struct listElement;
SortedList * createdSortedList();
bool isEmpty(SortedList *list);
void pushList(SortedList *list, const int data);
void printList(SortedList *list);
void deleteElement(SortedList *list, int data);
void deleteList(SortedList *list);