#pragma once

struct BST;
struct NodeBST;
BST *createBST();
bool isEmpty(BST *tree);
void printDecreasing(BST *tree);
void doPrintDecreasing(NodeBST *tree);
void printIncreasing(BST *tree);
void doPrintIncreasing(NodeBST *tree);
void add(BST *tree, int data);
void addNode(NodeBST *node, int data);
NodeBST* find(BST *tree, int data);
NodeBST* doFind(NodeBST *node, int data);
NodeBST* findMin(BST *tree);
NodeBST* doFindMin(NodeBST *node);
void deleteNode(BST *tree, int data);
void doDeleteNode(NodeBST *node);