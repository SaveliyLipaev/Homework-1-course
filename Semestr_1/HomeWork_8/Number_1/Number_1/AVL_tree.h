#pragma once

#include <string>

struct AvlTree;
struct TreeNode;

//function that returns the address of the selected memory cell to the AvlTree structure
AvlTree* createAvlTree();

//a function that returns the height of this node
int height(const TreeNode *node);

//function returning the height difference of the children of this node
int heightDifference(const TreeNode *node);

//the function returns true if the tree is empty
bool isEmpty(const AvlTree *tree);

//function recalculating the height of the node
void newHeight(TreeNode *node);

//right turn knot
TreeNode* rightTurn(TreeNode *node, AvlTree *tree);

//left turn knot
TreeNode* leftTurn(TreeNode *node, AvlTree *tree);

//function restoring the balance in the node
TreeNode* balance(TreeNode *node, AvlTree *tree);

//function that adds an element to the tree
void push(AvlTree *tree, const int key, const std::string str);

//feature helps push function
TreeNode* doPush(TreeNode *node, AvlTree *tree, const int key, const std::string str);

//function that removes a node in the tree by key
void deleteNode(AvlTree *tree, const int key);

//feature helps deleteNode function
TreeNode* doDeleteNode(TreeNode *node, AvlTree *tree, const int key);

//the function returns a string by key
std::string takingString(const AvlTree *tree, const int key);

//feature helps takingString function
std::string doTakingString(const TreeNode *node, const int key);

//The function returns true if the item is found in the tree
bool elementIsPresent(const AvlTree *tree, const int key);

//feature helps takingString function
bool doElementIsPresent(const TreeNode *node, const int key);

//function remove all subtree
void deleteSubtree(TreeNode *node);

//function remove all tree
void deleteTree(AvlTree *tree);