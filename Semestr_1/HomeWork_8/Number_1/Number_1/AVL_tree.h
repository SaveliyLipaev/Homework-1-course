#pragma once

#include <string>

struct AvlTree;
struct TreeNode;
AvlTree* createAvlTree();
int height(TreeNode *node);
int heightDifference(TreeNode *node);
bool isEmpty(AvlTree *tree);
void newHeight(TreeNode *node);
TreeNode* rightTurn(TreeNode *node, AvlTree *tree);
TreeNode* leftTurn(TreeNode *node, AvlTree *tree);
TreeNode* balance(TreeNode *node, AvlTree *tree);
void push(AvlTree *tree, int key, std::string str);
TreeNode* doPush(TreeNode *node, AvlTree *tree, int key, std::string str);
void deleteNode(AvlTree *tree, int key);
TreeNode* doDeleteNode(TreeNode *node, AvlTree *tree, int key);
std::string takingString(AvlTree *tree, int key);
std::string doTakingString(TreeNode *node, int key);
bool elementIsPresent(AvlTree *tree, int key);
bool doElementIsPresent(TreeNode *node, int key);
void deleteSubtree(TreeNode *node);
void deleteTree(AvlTree *tree);