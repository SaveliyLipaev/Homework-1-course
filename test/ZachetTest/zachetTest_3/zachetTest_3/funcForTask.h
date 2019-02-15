#pragma once

void bypass(int **graph, bool *visitedVertex, int index, int quantityArcs, int quantityVertex, int currentVertex);
bool isGoodVertex(bool *visitedVertex, int quantityVertex);
void findGoodVertex(int **graph, int quantityVertex, int quantityArc);