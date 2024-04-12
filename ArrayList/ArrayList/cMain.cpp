#include "ArrayList.h"

int main()
{
	ArrayList arr;

	arr.InsertNode(1,3,2);
	arr.AddNode(1);
	arr.InsertNode(1, 3, 2);

	arr.DeleteNodeData(2);

	arr.PrintAll();

}
