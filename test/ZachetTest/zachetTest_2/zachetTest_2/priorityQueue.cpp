struct Node
{
	int key = 0;
	int data = 0;
	Node *next = nullptr;
};

struct PriorityQueue
{
	Node *head = nullptr;
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
	Node * newNode = new Node{ key, data, nullptr };

	if (isEmpty(queue) || key < queue->head->key)
	{
		newNode->next = queue->head;
		queue->head = newNode;
		return;
	}
	Node *temp = queue->head;
	while (temp->next != nullptr && temp->next->key < key)
	{
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
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