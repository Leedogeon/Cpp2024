#include "BinaryTree.h"

int main()
{
	BinaryTree BT;
	BT.AddNode(2);
	BT.AddNode(1);
	BT.AddNode(3);
	BT.AddNode(4);


	BT.RemoveNode(1);

	//BT.PrintAll();
	//cout << BT.rootNode->right->right->data << endl;
}