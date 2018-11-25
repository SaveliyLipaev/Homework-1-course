#pragma once

#include <string>

struct AvlTree;

//function that returns the address of the selected memory cell to the AvlTree structure
AvlTree* createAvlTree();

//the function returns true if the tree is empty
bool isEmpty(const AvlTree *tree);

//function that adds an element to the tree
void push(AvlTree *tree, const int key, const std::string str);

//the function returns a string by key
std::string takingString(const AvlTree *tree, const int key);

//The function returns true if the item is found in the tree
bool elementIsPresent(const AvlTree *tree, const int key);

//function remove all tree
void deleteTree(AvlTree *tree);

//function when delete node in tree by key
void deleteNode(AvlTree *tree, const int key);