#pragma once

struct Stack;

//A function that returns a pointer to the allocated memory for the Stack type
Stack *createStack();

//Function that adds an item to the stack
void push(Stack *stack, int data);

//The function that removes an item in the stack that the head points to.
//and returns the data of this item.
int pop(Stack *stack);

//The function returns true if the stack is empty
bool isEmpty(Stack *stack);

//The function that clears the memory that occupied the stack
void deleteStack(Stack *stack);

//a function that returns the data of the element that the head points to
int lastValue(Stack *stack);