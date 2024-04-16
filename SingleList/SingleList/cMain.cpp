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

	cout << "///////" << endl;
	sin.DeleteIndex(4);
	
	sin.PrintAll();
	//cout << sin.head->data << endl;
	//cout << sin.head->next->data << endl;
	//cout << sin.head->next->next->data << endl;
	//cout << sin.head->next->next->next->data << endl;
	//cout << sin.head->next->next->next->next->data << endl;


}
