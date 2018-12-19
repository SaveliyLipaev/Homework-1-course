#include "graphForTasks10.1.h"
#include "Test.h"
#include <vector>
#include <iostream>
#include <list>
#include <fstream>

int main()
{
	if (test())
	{
		std::cout << "Test passed!!!\n\n";
	}
	else
	{
		std::cout << "Test failed!!!\n\n";
		return -1;
	}


	std::ifstream file("inputFile.txt");
	if (!file.is_open())
	{
		std::cout << "File dont open!!\n";
		return -1;
	}

	int quantityCities = 0;
	int quantityRoads = 0;
	file >> quantityCities >> quantityRoads;

	auto graph = createGraph(quantityCities);     //создаем вершины

	for (int i = 0; i < quantityRoads; ++i)       //создаем дуги
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

	for (int i = 0; i < quantityStates; ++i)       //отмечаем столицы
	{
		file >> stateNumbers[i];
		changeState(graph, stateNumbers[i], stateNumbers[i]);
	}

	bool flagHaveToCapture = true;
	while (flagHaveToCapture)                      //захват городов
	{
		flagHaveToCapture = false;
		for (int i = 0; i < quantityStates; ++i)
		{
			flagHaveToCapture = captureCity(graph, stateNumbers[i]) || flagHaveToCapture;
		} 
	}

	std::vector<std::list<int>> result(quantityStates);         //массив списков для вывода ответа

	for (int i = 0; i < quantityCities; ++i)
	{
		for (int j = 0; j < quantityStates; ++j)
		{
			if (stateNumbers[j] == returnState(graph, i + 1))
			{
				result[j].push_front(i + 1);
				break;
			}
		}
	}

	for (int i = 0; i < quantityStates; ++i)          //вывод ответа
	{
		std::cout << stateNumbers[i] << "   -   ";
		for (auto temp : result[i])
		{
			std::cout << temp << ' ';
		}
		std::cout << std::endl;
	}

	file.close();
	deleteGraph(graph);
	return 0;
}