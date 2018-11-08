#pragma once

struct BST;
struct NodeBST;
BST *createBST();
bool isEmpty(BST *tree);
void printDecreasingBST(BST *tree);
void printDecreasingTree(NodeBST *tree);
void printIncreasingBST(BST *tree);
void printIncreasingTree(NodeBST *tree);
void addNodeBST(BST *tree, int data);
void addNode(NodeBST *node, int data);