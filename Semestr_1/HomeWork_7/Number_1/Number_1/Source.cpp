#include "BST.h"
#include <iostream>

using namespace std;


int main()
{
	auto tree = createBST();
	add(tree, 22);
	add(tree, 25);
	deleteNode(tree, 25);
	add(tree, 20);

	printDecreasing(tree);
	cout << endl;
	printIncreasing(tree);
	

	return 0;
}