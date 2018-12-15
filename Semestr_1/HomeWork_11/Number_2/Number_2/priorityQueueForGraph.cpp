#include "priorityQueueForGraph.h"

struct Node
{
	int key = 0;
	int firstVertex = 0;
	int secondVertex = 0;
	Node *next = nullptr;
};

struct PriorityQueue
{
	Node *head = nullptr;
};

PriorityQueue *createQueue()
{
	return new PriorityQueue;
}

bool isEmpty(PriorityQueue *queue)
{
	return queue->head == nullptr;
}

void push(PriorityQueue *queue, const int key, const int firstVertex, const int secondVertex)
{
	const auto newElement = new Node{ key, firstVertex, secondVertex, nullptr };
	if (isEmpty(queue))
	{
		queue->head = newElement;
	}
	else
	{
		Node *leftNode = nullptr;
		Node *rightNode = queue->head;
		while (rightNode != nullptr && newElement->key > rightNode->key)
		{
			leftNode = rightNode;
			rightNode = rightNode->next;
		}
		if (leftNode != nullptr)
		{
			newElement->next = rightNode;
			leftNode->next = newElement;
		}
		else
		{
			newElement->next = queue->head;
			queue->head = newElement;
		}
	}
}

void deleteQueue(PriorityQueue *&queue)
{
	while (!isEmpty(queue))
	{
		const Node *temp = queue->head;
		queue->head = queue->head->next;
		delete temp;
	}
	delete queue;
}

void pop(PriorityQueue *queue)
{
	if (queue->head != nullptr)
	{
		auto temp = queue->head;
		queue->head = temp->next;
		delete temp;
	}
}

int returnFirstVertex(PriorityQueue *queue)
{
	return queue->head->firstVertex;
}

int returnSecondVertex(PriorityQueue *queue)
{
	return queue->head->secondVertex;
}