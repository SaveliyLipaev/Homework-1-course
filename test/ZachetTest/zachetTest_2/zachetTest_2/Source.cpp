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
	int temp3 = dequeue(queue);
	int temp4 = dequeue(queue);

	cout << temp << endl << temp2 << endl << temp3 << endl << temp4;

	deletePriorityQueue(queue);
	return 0;
}