#include "CircularList.h"

int main()
{
	CircularList cir;
	cir.AddNode(10);
	cir.AddNode(20);
	cir.AddNode(30);
	cir.InsertNode(1, 100);
	cir.DeleteIndex(1);
	cir.DeleteNodeData(20);
	cir.PrintAll();
	cout <<cir.Count() << endl;

	cout << cir.GetNodeData(1) << endl;


	

}