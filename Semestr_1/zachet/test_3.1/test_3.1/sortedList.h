#pragma once

struct SortedList;
SortedList * createdSortedList();
bool isEmpty(SortedList *list);
void pushList(SortedList *list, const int data);
void printList(SortedList *list);
void deleteList(SortedList *list);