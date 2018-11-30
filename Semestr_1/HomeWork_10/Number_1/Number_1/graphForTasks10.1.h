#pragma once

struct Graph;

//Returns the address of the selected memory cell on the graph
//structure, also allocates memory for lists inside the vector
Graph* createGraph(const int &numberNode);

//adds an arc between vertices of length 'length'
void addArc(Graph *graph, const int &nodeOne, const int &nodeTwo, const int &length);

//deletes the graph as well as lists inside the graph
void deleteGraph(Graph *graph);

//returns the state number to which the given city belongs
int returnState(Graph *graph, const int &node);

//seizes power in this city
void changeState(Graph *graph, const int &node, const int &newState);

//seizes power in the nearest city from the state
bool captureCity(Graph *graph, const int capital);