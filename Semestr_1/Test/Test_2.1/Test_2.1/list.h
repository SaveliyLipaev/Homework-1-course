#pragma once

struct List;
List *createList();
void push(List *list, int data);
int pop(List *list);
bool isEmpty(List *list);
void deleteList(List *list);
List *coupList(List *list);
void printList(List *list);
int lastValue(List *list);