#pragma once

struct BST;

//returns the address for the allocated memory for the BST structure
BST *createBST();

//returns true if the tree is empty
bool isEmpty(BST *tree);

//prints dozens in descending order
void printDecreasing(BST *tree);

//prints dozens in increasing order
void printIncreasing(BST *tree);

//the function adds an element to the set
void add(BST *tree, int data);

//the function returns true if the item is found
bool find(BST *tree, int data);

//function removes item by key
void terriblyUglyDeleteNode(BST *tree, int data);

//the function removes the element pointed to by the head
void deleteFirstElement(BST *tree);

//the function deletes the whole tree
void deleteBST(BST *tree);