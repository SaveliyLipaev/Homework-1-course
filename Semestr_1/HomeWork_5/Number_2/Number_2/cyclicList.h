#pragma once

struct CyclicList;
struct node;
CyclicList *createdCyclicList();
bool isEmpty(CyclicList *list);
void push(CyclicList *list, const int data);
void deleteList(CyclicList *list);
int killsWarriors(CyclicList *list, const int step);