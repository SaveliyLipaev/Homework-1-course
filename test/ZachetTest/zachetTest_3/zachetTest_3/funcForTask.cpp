#include <iostream>
#include <fstream>

int findAnotherCity(int **graph, int n, int index)
{
	for (int i = 0; i < n; i++)
	{
		if (graph[i][index] == 1)
		{
			return i;
		}
	}

	return 0;
}

bool isRightNode(bool *vertex, int quantityVertex)
{
	for (int i = 0; i < quantityVertex; i++)
	{
		if (!vertex[i])
		{
			return false;
		}
	}
	return true;
}

void printNode(bool *vertex, int quantinyVertex)
{
	for (int i = 0; i < quantinyVertex; i++)
	{
		std::cout << vertex[i] << ' ';
	}
}

void bypass(int **graph, bool *vertex, int index, int m, int n, int currentCity)
{
	for (int i = 0; i < m; i++)
	{
		if (graph[index][i] == -1)
		{
			int numberOfCity = findAnotherCity(graph, n, i);
			if (!vertex[numberOfCity])
			{
				vertex[numberOfCity] = true;
				bypass(graph, vertex, numberOfCity, m, n, currentCity);
			}
		}
	}
}

void find(int **graph, bool *vertex, int quantityVertex, int quantityArc)
{
	for (int i = 0; i < quantityVertex; i++)
	{
		for (int i = 0; i < quantityVertex; i++)
		{
			vertex[i] = false;
		}

		bypass(graph, vertex, i, quantityArc, quantityVertex, i);
		vertex[i] = true;
		if (isRightNode(vertex, quantityVertex))
		{
			std::cout << i + 1 << std::endl;
		}
	}
}