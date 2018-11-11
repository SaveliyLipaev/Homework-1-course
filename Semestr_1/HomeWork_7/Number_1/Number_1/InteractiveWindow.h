#pragma once

#include <iostream>
#include "BST.h"
using namespace std;

//the function calls the interactive window and works with it, calling the necessary functions
void interactiveWindows(BST *tree);

//the function asks for which element to add and adds it
void addElement(BST *tree);

//the function asks for which element to delete and deleted it
void deleteElement(BST *tree);

//the function asks for which element to check for membership and returns true if this element belongs to the set
void affiliationElement(BST *tree);