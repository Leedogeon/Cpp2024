#include "SingleList.h"
int main()
{
	SingleList sin;
	sin.AddNode(10);
	sin.AddNode(20);
	sin.AddNode(30);
	sin.AddNode(40);
	sin.InsertNode(0, 50);
	sin.PrintAll();

	sin.ClearAllNode();
	sin.PrintAll();

	sin.AddNode(10);
	sin.PrintAll();

}
