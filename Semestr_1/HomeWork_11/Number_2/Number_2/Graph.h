#pragma once

struct Graph;

//creates a graph with the given number vertices
Graph* createGraph(const int numberNode);

//add arc
void addArc(Graph *graph, const int firstVertex, const int secondVertex, const int value);

//forms the minimum spanning tree, 
//if you pass true, then print out the edges belonging to this tree
void highlightOstovTree(Graph *graph, const bool print);

//delete Graph
void deleteGraph(Graph *graph);