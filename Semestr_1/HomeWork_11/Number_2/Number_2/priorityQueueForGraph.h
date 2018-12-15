#pragma once

struct PriorityQueue;

//returns the address of the selected cell in memory on the structure of the PriorityQueue
PriorityQueue *createQueue();

//returns true if the queue is empty
bool isEmpty(PriorityQueue *queue);

//adds an item to the queue
void push(PriorityQueue *queue, const int key, const int firstVertex, const int secondVertex);

//delete queue
void deleteQueue(PriorityQueue *&queue);

//deletes the first item in the queue
void pop(PriorityQueue *queue);

//returns field second vertex
int returnSecondVertex(PriorityQueue *queue);

//returns field first vertex
int returnFirstVertex(PriorityQueue *queue);