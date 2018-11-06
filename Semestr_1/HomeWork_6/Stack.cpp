#include "Stack.h"

struct Stack
{
	nodeStack *head = nullptr;
};

struct nodeStack
{
	int data;
	nodeStack *next;
};

Stack *createStack()
{
	return new Stack;
}

void push(Stack *stack, int data)
{
	auto newNode = new nodeStack{ data, stack->head };
	stack->head = newNode;
}

int pop(Stack *stack)
{
	auto temp = stack->head;
	const int value = temp->data;
	stack->head = temp->next;
	delete temp;
	return value;
}

bool isEmpty(Stack *stack)
{
	return stack->head == nullptr;
}

void deleteStack(Stack *stack)
{
	while (stack->head != nullptr)
	{
		auto temp = stack->head;
		stack->head = temp->next;
		delete temp;
	}
	delete stack;
}

int lastValue(Stack *stack)
{
	return stack->head->data;
}