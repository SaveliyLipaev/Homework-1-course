#pragma once


struct PriorityQueue;
PriorityQueue *createPriorityQueue();
bool isEmpty(PriorityQueue *queue);
void enqueue(PriorityQueue *queue, const int key, const int data);
void deletePriorityQueue(PriorityQueue *&queue);
int dequeue(PriorityQueue *queue);