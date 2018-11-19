#include "stackFor9.1.h"
#include <string>

using namespace std;

struct Stack
{
	NodeStack *head = nullptr;
};

Stack *createStack()
{
	return new Stack;
}

void push(Stack *stack, string str)
{
	auto newNode = new NodeStack{ str, 0, stack->head };
	stack->head = newNode;
}

void pop(Stack *stack)
{
	auto temp = stack->head;
	stack->head = temp->next;
	delete temp;
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

NodeStack* findNode(Stack *stack, string str)
{
	auto temp = stack->head;
	while (temp != nullptr)
	{
		if (temp->str == str)
		{
			return temp;
		}
		temp = temp->next;
	}
	return temp;
}