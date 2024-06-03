#include "MST.h"

int main()
{
	MST dx;

	dx.Init(Max);

	dx.AddEdge(1, 2, 3);
	dx.AddEdge(1, 4, 2);
	dx.AddEdge(1, 3, 10);
	dx.AddEdge(2, 4, 3);
	dx.AddEdge(2, 3, 5);
	dx.AddEdge(3, 5, 1);
	dx.AddEdge(3, 6, 5);
	dx.AddEdge(4, 5, 2);
	dx.AddEdge(4, 6, 4);
	dx.AddEdge(5, 6, 2);


	for (int i = 0; i < Max; i++)
	{
		dx.ShowGraphEdge(i);
	}
	dx.BreadthFirstSerch();

}