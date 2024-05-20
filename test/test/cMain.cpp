#include <iostream>
using namespace std;

struct Node
{
	int x;
	Node* parent;
};
Node arr[3][3] = {};
void test(Node *cNode);
int main()
{
	Node cNode = arr[0][0];
	cNode.x = 1;

	test(&cNode);


	cout << &cNode << endl;


}
void test(Node *cNode)
{
	cout << cNode << endl;
	arr[0][1].parent = cNode;

}