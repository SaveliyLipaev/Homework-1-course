#include "stackFor9.1.h"
#include <string>
#include <iostream>

using namespace std;


Stack *createStack()
{
	return new Stack;
}

void push(Stack *stack, string str)
{
	auto newNode = new NodeStack{ str, 1, stack->head };
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

void printStack(Stack* stack)
{
	auto temp = stack->head;
	while (temp != nullptr)
	{
		cout << temp->str << " - " << temp->quantity << endl;
		temp = temp->next;
	}
}