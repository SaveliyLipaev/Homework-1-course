#include "BST.h"
#include <iostream>

using namespace std;

int main()
{
	auto tree = createBST();
	addNodeBST(tree, 22);
	addNodeBST(tree, 25);
	addNodeBST(tree, 20);

	printDecreasingBST(tree);
	cout << endl;
	printIncreasingBST(tree);



	return 0;
}