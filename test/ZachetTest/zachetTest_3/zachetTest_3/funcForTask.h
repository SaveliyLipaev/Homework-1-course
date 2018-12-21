#pragma once

void find(int **graph, bool *vertex, int quantityVertex, int quantityArc);
void bypass(int **graph, bool *vertex, int index, int m, int n, int currentCity);
void printNode(bool *vertex, int quantinyVertex);
bool isRightNode(bool *vertex, int quantityVertex);
int findAnotherCity(int **graph, int n, int index);