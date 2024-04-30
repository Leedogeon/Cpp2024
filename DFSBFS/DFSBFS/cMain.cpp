#include "Graph.h"

int main()
{
	Graph gr;

	gr.InitializeGraph(maxCount);
	gr.AddEdge(1, 5);
	gr.AddEdge(1, 4);
	gr.AddEdge(1, 6);
	gr.AddEdge(0, 4);
	gr.AddEdge(0, 7);
	gr.AddEdge(6, 4);
	gr.AddEdge(6, 0);
	gr.AddEdge(2, 4);
	gr.AddEdge(2, 3);
	gr.AddEdge(2, 0);
	gr.AddEdge(3, 7);
	gr.AddEdge(5, 3);


	for (int i = 0; i < maxCount; i++)
	{
		gr.ShowGraphEdge(i);
	}

	gr.DepthFirstSerch(1);

	gr.BreadthFirstSerch(1);







}