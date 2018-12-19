#include "graphForTasks10.1.h"
#include <fstream>
#include <vector>

bool test()
{
	std::ifstream file("FileForTest.txt");
	if (!file.is_open())
	{
		return false;
	}

	int quantityCities = 0;
	int quantityRoads = 0;
	file >> quantityCities >> quantityRoads;

	auto graph = createGraph(quantityCities);     

	for (int i = 0; i < quantityRoads; ++i)
	{
		int bufferOne = 0;
		int bufferTwo = 0;
		int bufferTree = 0;
		file >> bufferOne >> bufferTwo >> bufferTree;
		addArc(graph, bufferOne, bufferTwo, bufferTree);
	}
	
	int quantityStates = 0;
	file >> quantityStates;
	std::vector<int> stateNumbers(quantityStates);

	for (int i = 0; i < quantityStates; ++i)       
	{
		file >> stateNumbers[i];
		changeState(graph, stateNumbers[i], stateNumbers[i]);
	}

	bool flagHaveToCapture = true;
	while (flagHaveToCapture)                      
	{
		flagHaveToCapture = false;
		for (int i = 0; i < quantityStates; ++i)
		{
			flagHaveToCapture = captureCity(graph, stateNumbers[i]) || flagHaveToCapture;
		}
	}
	
	if (returnState(graph, 9) != 1 || returnState(graph, 7) != 1 || returnState(graph, 6) != 2 || returnState(graph, 5) != 3 || returnState(graph, 8) != 4)
	{
		deleteGraph(graph);
		return false;
	}

	deleteGraph(graph);
	return true;
}