
struct NodeList
{
	int node = 0;
	int length = 0;
	NodeList *next;
};

struct List
{
	int length = 0;
	NodeList *head = nullptr;
};

bool isEmpty(List *list)
{
	return list->head == nullptr;
}

List* createList()
{
	return new List;
}

void push(List *list, const int &node, const int &length)
{
	auto newNode = new NodeList{ node, length, list->head };
	list->head = newNode;
	++list->length;
}

void pop(List *list)
{
	auto temp = list->head;
	list->head = temp->next;
	delete temp;
}

void deleteList(List *list)
{
	if (list == nullptr)
	{
		return;
	}
	while (list->head != nullptr)
	{
		auto temp = list->head;
		list->head = temp->next;
		delete temp;
	}
	delete list;
}

int lengthList(List *list)
{
	return list->length;
}

int returnNode(List *list, const int &number)
{
	auto temp = list->head;
	for (int i = 0; i < number; ++i)
	{
		temp = temp->next;
	}
	return temp->node;
}

int returnLengthArc(List *list, const int &number)
{
	auto temp = list->head;
	for (int i = 0; i < number; ++i)
	{
		temp = temp->next;
	}
	return temp->length;
}