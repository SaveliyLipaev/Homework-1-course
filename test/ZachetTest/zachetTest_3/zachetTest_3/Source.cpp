#include <iostream>
#include <fstream>
#include "funcForTask.h"


int main()
{
	std::ifstream file("graph.txt");

	int quantityVertex = 0;
	file >> quantityVertex;
	int quantityArcs = 0;
	file >> quantityArcs;
	int **graph = new int *[quantityVertex];

	for (int i = 0; i < quantityVertex; i++)
	{
		graph[i] = new int[quantityArcs];
		for (int j = 0; j < quantityArcs; j++)
		{
			file >> graph[i][j];
		}
	}

	file.close();

	findGoodVertex(graph, quantityVertex, quantityArcs);

	for (int i = 0; i < quantityVertex; i++)
	{
		delete[] graph[i];
	}
	delete[] graph;
	return 0;
}