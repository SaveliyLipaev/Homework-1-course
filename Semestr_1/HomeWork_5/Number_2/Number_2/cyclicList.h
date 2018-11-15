#pragma once

struct CyclicList;
struct Node;
CyclicList *createCyclicList();
bool isEmpty(CyclicList *list);
void push(CyclicList *list, const int data);
void deleteList(CyclicList *list);
int deleteWithStep(CyclicList *list, const int step);