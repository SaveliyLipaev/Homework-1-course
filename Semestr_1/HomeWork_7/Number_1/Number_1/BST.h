#pragma once

struct BST;
struct NodeBST;

//returns the address for the allocated memory for the BST structure
BST *createBST();

//returns true if the tree is empty
bool isEmpty(BST *tree);

//prints dozens in descending order
void printDecreasing(BST *tree);

//helps printDecrasing function print set in descending order
void doPrintDecreasing(NodeBST *tree);

//prints dozens in increasing order
void printIncreasing(BST *tree);

//helps printIncreasing function print set in increasing order
void doPrintIncreasing(NodeBST *tree);

//the function adds an element to the set
void add(BST *tree, int data);

//the function helps the add function to add an element to the set
void addNode(NodeBST *node, int data);

//the function returns true if the item is found
bool find(BST *tree, int data);

//function helps find function in searching for items in the tree
bool doFind(NodeBST *node, int data);

//function removes item by key
void terriblyUglyDeleteNode(BST *tree, int data);

//the function removes the element pointed to by the head
void deleteFirstElement(BST *tree);

//the function deletes the whole tree
void deleteBST(BST *tree);