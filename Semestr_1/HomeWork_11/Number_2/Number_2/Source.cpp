#include <fstream>
#include <iostream>
#include "Graph.h"
#include "Test.h"

int main()
{
	if (!test())
	{
		std::cout << "Test failed!\n";
		return -1;
	}
	std::ifstream file("adjacencyMatrix.txt");
	if (!file.is_open())
	{
		std::cout << "The file did not open!\n";
		return 1;
	}
	int numberVertices = 0;
	file >> numberVertices;
	auto graph = createGraph(numberVertices);
	for (int i = 0; i < numberVertices; ++i)
	{
		for (int j = 0; j < numberVertices; ++j)
		{
			int buffer = 0;
			file >> buffer;
			addArc(graph, i, j, buffer);
		}
	}
	std::cout << "These arcs form a ostov tree\n";
	highlightOstovTree(graph, true);
	deleteGraph(graph);
	file.close();
	return 0;
}