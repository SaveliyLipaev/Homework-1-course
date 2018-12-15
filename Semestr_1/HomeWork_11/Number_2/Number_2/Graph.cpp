#include <vector>
#include <iostream>
#include "priorityQueueForGraph.h"
#include "Graph.h"

struct Arc
{
	int length = 0;
	bool partOstov = false;
};

struct Graph
{
	std::vector<std::vector<Arc>> nodes;
};

Graph* createGraph(const int numberNode)
{
	auto graph = new Graph;
	graph->nodes.resize(numberNode);
	for (auto &temp : graph->nodes)
	{
		temp.resize(numberNode);
	}
	return graph;
}

void addArc(Graph *graph, const int firstVertex, const int secondVertex, const int value)
{
	graph->nodes[firstVertex][secondVertex].length = value;
	graph->nodes[secondVertex][firstVertex].length = value;
}

void highlightOstovTree(Graph *graph, const bool print)
{
	auto queueArc = createQueue();
	for (size_t i = 0; i < graph->nodes.size(); ++i)
	{
		for (size_t j = i + 1; j < graph->nodes.size(); ++j)
		{
			if (graph->nodes[i][j].length != 0)
			{
				push(queueArc, graph->nodes[i][j].length, i, j);
			}
		}
	}
	bool *affiliationOstov = new bool[graph->nodes.size()]{};
	while (!isEmpty(queueArc))
	{
		int firstVetrex = returnFirstVertex(queueArc);
		int secondVertex = returnSecondVertex(queueArc);
		pop(queueArc);
		if (affiliationOstov[firstVetrex] && affiliationOstov[secondVertex])
		{
			continue;
		}
		if (print)
		{
			std::cout << firstVetrex + 1 << "  -  " << secondVertex + 1 << std::endl;
		}
		graph->nodes[firstVetrex][secondVertex].partOstov = true;
		graph->nodes[secondVertex][firstVetrex].partOstov = true;
		affiliationOstov[firstVetrex] = true;
		affiliationOstov[secondVertex] = true;
	}

	delete[] affiliationOstov;
	deleteQueue(queueArc);
}

void deleteGraph(Graph *graph)
{
	for (auto &temp : graph->nodes)
	{
		temp.clear();
	}
	graph->nodes.clear();
	delete graph;
	graph = nullptr;
}

bool checkAffiliationOstov(Graph *graph, const int firstVertex, const int secondVertex)
{
	return graph->nodes[firstVertex][secondVertex].partOstov;
}