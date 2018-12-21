#include <iostream>
#include "priorityQueue.h"

using namespace std;

int main()
{
	auto queue = createPriorityQueue();
	enqueue(queue, 4, 1); 
	enqueue(queue, 3, 2);
	enqueue(queue, 3, 3);
	enqueue(queue, 4, 4);

	int temp = dequeue(queue);
	int temp2 = dequeue(queue);

	cout << temp << endl << temp2;

	deletePriorityQueue(queue);
	return 0;
}