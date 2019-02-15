#include <iostream>
#include "priorityQueue.h"

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


	std::cout << temp << std::endl << temp2 << std::endl << temp3 << std::endl;

	deletePriorityQueue(queue);
	return 0;
}