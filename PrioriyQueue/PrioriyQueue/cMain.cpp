#include "PriorityQueue.h"

int main()
{
	PriorityQueue PQ;

	PQ.Push(3,3);
	PQ.Push(2, 2);
	PQ.Push(1, 1);
	PQ.Push(4, 4);
	PQ.Push(8, 8);
	PQ.Push(11, 11);
	PQ.Push(12, 12);
	PQ.Push(19, 19);
	PQ.Push(18, 18);



	PQ.PrintAll();

	PQ.Pop();

	cout << "----------" << endl;

	PQ.PrintAll();

	PQ.Pop();

	cout << "----------" << endl;

	PQ.PrintAll();

	PQ.Pop();

	cout << "----------" << endl;

	PQ.PrintAll();


}