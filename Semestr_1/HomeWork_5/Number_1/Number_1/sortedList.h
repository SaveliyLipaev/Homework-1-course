#pragma once


struct SortedList;
struct ListElement;
SortedList * createdSortedList();
bool isEmpty(SortedList *list);
void pushList(SortedList *list, const int data);
void printList(SortedList *list);
void deleteElement(SortedList *list, int data);
void deleteList(SortedList *list);
bool checkSortingList(SortedList *list);