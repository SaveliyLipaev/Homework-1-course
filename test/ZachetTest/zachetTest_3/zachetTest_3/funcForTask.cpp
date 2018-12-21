#include <iostream>

int findVertex(int **graph, int quantityVertex, int index)
{
	for (int i = 0; i < quantityVertex; i++)
	{
		if (graph[i][index] == 1)
		{
			return i;
		}
	}
	return 0;
}

bool isGoodVertex(bool *visitedVertex, int quantityVertex)
{
	for (int i = 0; i < quantityVertex; i++)
	{
		if (!visitedVertex[i])
		{
			return false;
		}
	}
	return true;
}

void bypass(int **graph, bool *visitedVertex, int index, int quantityArcs, int quantityVertex, int currentVertex)
{
	for (int i = 0; i < quantityArcs; i++)
	{
		if (graph[index][i] == -1)
		{
			int numberVertex = findVertex(graph, quantityVertex, i);
			if (!visitedVertex[numberVertex])
			{
				visitedVertex[numberVertex] = true;
				bypass(graph, visitedVertex, numberVertex, quantityArcs, quantityVertex, currentVertex);
			}
		}
	}
}

void findGoodVertex(int **graph, int quantityVertex, int quantityArc)
{
	for (int i = 0; i < quantityVertex; i++)
	{
		bool *visitedVertex = new bool[quantityVertex] {};
		visitedVertex[i] = true;
		bypass(graph, visitedVertex, i, quantityArc, quantityVertex, i);
		if (isGoodVertex(visitedVertex, quantityVertex))
		{
			std::cout << i << std::endl;
		}
		delete[] visitedVertex;
	}
}