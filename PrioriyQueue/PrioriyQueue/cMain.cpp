#include "PriorityQueue.h"

int main()
{
	PriorityQueue PQ;

	PQ.Push(3,1);
	PQ.Push(2, 1);
	PQ.Push(1, 1);

	cout << PQ.Count() << endl;


	PQ.Pop();

	cout << PQ.Count() << endl;

}