#include "Graph.h"
#include <fstream>

bool checkAffiliationOstov(Graph *graph, int firstVertex, int secondVertex);

bool test()
{
	std::ifstream file("adjacencyMatrix.txt");
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
	file.close();
	highlightOstovTree(graph, false);
	if (checkAffiliationOstov(graph, 0, 1) && checkAffiliationOstov(graph, 0, 2) 
		&& checkAffiliationOstov(graph, 2, 3) && !checkAffiliationOstov(graph, 3, 4))
	{
		deleteGraph(graph);
		return true;
	}
	deleteGraph(graph);
	return false;
}