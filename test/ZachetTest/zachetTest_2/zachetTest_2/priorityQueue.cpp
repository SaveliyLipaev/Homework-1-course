struct Node
{
	int key = 0;
	int data = 0;
	Node *next = nullptr;
	Node *previous = nullptr;
};

struct PriorityQueue
{
	Node *head = nullptr;
	Node *tail = nullptr;
};

PriorityQueue *createPriorityQueue()
{
	return new PriorityQueue;
}

bool isEmpty(PriorityQueue *queue)
{
	return queue->head == nullptr;
}

void enqueue(PriorityQueue *queue, const int key, const int data)
{
	auto newElement = new Node{ key, data, queue->head, nullptr };

	while (newElement->next && newElement->next->key >= key)
	{
		newElement->previous = newElement->next;
		newElement->next = newElement->next->next;
	}

	if (newElement->previous)
	{
		newElement->previous->next = newElement;
	}
	else 
	{
		queue->head = newElement;
	}

	if (newElement->next)
	{
		newElement->next->previous = newElement;
	}
	else 
	{
		queue->tail = newElement;
	}
}

void deletePriorityQueue(PriorityQueue *&queue)
{
	while (!isEmpty(queue))
	{
		const Node *temp = queue->head;
		queue->head = queue->head->next;
		delete temp;
	}
	delete queue;
}

int dequeue(PriorityQueue *queue)
{
	if (queue->head != nullptr)
	{
		const int value = queue->head->data;
		auto temp = queue->head;
		queue->head = temp->next;
		delete temp;
		return value;
	}
	return -1;
}