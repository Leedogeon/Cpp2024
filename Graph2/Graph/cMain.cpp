#include "Graph.h"
int main()
{
	Graph graph;

	graph.InitializeGraph(9);

	graph.AddEdge(0, 2);
	graph.AddEdge(0, 1);

	graph.AddEdge(0, 3);

	graph.DeleteEdge(0, 1);

	graph.ShowGraphEdge(0);
}