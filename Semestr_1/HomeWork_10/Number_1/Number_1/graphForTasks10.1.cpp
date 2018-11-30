#include <vector>
#include <queue>
#include "ListForGraph.h"

struct Node
{
	int state = 0;
	List* list;
};

struct Graph
{
	std::vector<Node> nodes;
};

Graph* createGraph(const int &numberNode)
{
	auto graph = new Graph;
	graph->nodes.resize(numberNode);
	for (auto &temp : graph->nodes)
	{
		temp.list = createList();
	}
	return graph;
}

void addArc(Graph *graph, const int &nodeOne, const int &nodeTwo, const int &length)
{
	push(graph->nodes[nodeOne - 1].list, nodeTwo, length);
	push(graph->nodes[nodeTwo - 1].list, nodeOne, length);
}

void deleteGraph(Graph *graph)
{
	for (auto &temp : graph->nodes)
	{
		deleteList(temp.list);
	}
	graph->nodes.clear();
	delete graph;
}

int returnState(Graph *graph, const int &node)
{
	return graph->nodes[node - 1].state;
}

void changeState(Graph *graph, const int &node, const int &newState)
{
	graph->nodes[node - 1].state = newState;
}

bool captureCity(Graph *graph, const int capital)
{
	int minLength = INT_MAX;
	int minNode = 0;                                   //Сюда будем запоминать вершину до которой расстояние от государства минимально

	std::vector<bool> helpMas(graph->nodes.size());    //Массив в котором будем отмечать в какой вершине уже были
	std::queue<int> queue;
	queue.push(capital);

	while (!queue.empty())
	{
		auto targetNode = queue.front() - 1;
		queue.pop();
		helpMas[targetNode] = true;

		for (int i = 0; i < lengthList(graph->nodes[targetNode].list); ++i)
		{   
			if (graph->nodes[targetNode].state == 0 && returnState(graph, returnNode(graph->nodes[targetNode].list,i)) == capital && returnLengthArc(graph->nodes[targetNode].list, i) <= minLength)
			{
				minLength = returnLengthArc(graph->nodes[targetNode].list, i);
				minNode = targetNode;
			}
			else if (graph->nodes[targetNode].state == capital && !helpMas[returnNode(graph->nodes[targetNode].list, i) - 1])
			{
				queue.push(returnNode(graph->nodes[targetNode].list, i));
			}
		}
	}
	if (minNode == 0)
	{
		return false;                                //возвращает false если нет свободного города у границы
	}
	graph->nodes[minNode].state = capital;           //собственно сам захват ближайшего города
	return true;
}