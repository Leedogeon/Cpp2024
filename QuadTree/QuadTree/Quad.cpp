#include "Quad.h"

void Quad::AddData(int x, int y, int data)
{
	arr[y][x]->x = x;
	arr[y][x]->x = y;
	arr[y][x]->data = data;

}

void Quad::FindAll()
{
	Node* nNode = createNode(nullptr);
	if (rootNode == nullptr) rootNode = nNode;
	
	FindData(nNode, MaxX, MaxY, 0, 0);
}

void Quad::PrintAll(Node* cNode)
{
	list<XY*>::iterator iter = cNode->data.begin();

	for (auto num: cNode->data)
	{
		cout << num->data << endl;
	}
	cout << endl;
}


Node* Quad::createNode(Node* parent)
{
	Node* nNode = new Node(parent);
	return nNode;
}

void Quad::FindData(Node* nNode,int Mx, int My, int Lx, int Ly)
{
	cout << "MX = " << Mx << endl;
	cout << "LX = " << Lx << endl;
	cout << "MY = " << My << endl;
	cout << "LY = " << Ly << endl;


	FindUL(nNode,Mx,My,Lx,Ly);
	FindUR(nNode, Mx, My, Lx, Ly);
	FindDL(nNode, Mx, My, Lx, Ly);
	FindDR(nNode, Mx, My, Lx, Ly);
}

void Quad::FindUL(Node* nNode, int Mx, int My, int Lx, int Ly)
{
	int x1 = Lx + (Mx - Lx) / 2;
	int y1 = My - (My - Ly) / 2;
	int x2 = Lx + (x1-Lx) / 2;
	int y2 = My - (My - y1) / 2;

	Node* next = createNode(nNode);
	nNode->UL = next;
	
	insertData(next, Mx, My, Lx, Ly, x2, y2);
	if (x2 - Lx == 1) return;

	FindData(next,x1, My, Lx, y1);
}

void Quad::FindUR(Node* nNode, int Mx, int My, int Lx, int Ly)
{
	cout << "UR" << endl;
	int x1 = Lx + (Mx - Lx) / 2;
	int y1 = My - (My - Ly) / 2;
	int x2 = Lx + (Mx - x1) / 2;
	int y2 = My - (My - y1) / 2;

	Node* next = createNode(nNode);
	nNode->UR = next;

	insertData(next, Mx, My, Lx, Ly, x2, y2);
	if (Mx - x2 == 1) return;
	FindData(next, Mx, My, x1, y1);
}

void Quad::FindDL(Node* nNode, int Mx, int My, int Lx, int Ly)
{
	int x1 = (Mx - Lx) / 2;
	int y1 = (My - Ly) / 2;
	int x2 = (x1 - Lx) / 2;
	int y2 = y1 - (y1-Lx) / 2;
	if (Mx == x1 && My == y1) return;

	Node* next = createNode(nNode);
	nNode->DL = next;
	next->parent = nNode->DL;
	insertData(next, Mx, My, Lx, Ly, x2, y2);
	FindData(next, Mx, My, x1, y1);
}
void Quad::FindDR(Node* nNode, int Mx, int My, int Lx, int Ly)
{
	int x1 = (Mx - Lx) / 2;
	int y1 = (My - Ly) / 2;
	int x2 = Mx - (Mx - x1) / 2;
	int y2 = y1 - (y1 - Lx) / 2;
	if (Mx == x1 && My == y1) return;

	Node* next = createNode(nNode);
	nNode->DR= next;
	next->parent = nNode->DR;
	insertData(next, Mx, My, Lx, Ly, x2, y2);
	FindData(next, Mx, My, x1, y1);
}

void Quad::insertData(Node* next, int Mx, int My, int Lx, int Ly, int x2, int y2)
{

	int resX = x2 - Lx;
	int resY = My - (My - Lx) / 2;
	if (resX == 1)
	{
		if (arr[y2][x2]->data != 0)
		{
			cout << arr[y2][x2]->data << endl;
			next->parent->data.push_back(arr[y2][x2]);
			delete(next);
		}
		cout << "t" << endl;
		return;
	}


	for (int i = Ly; i < My; i++)
	{
		if (arr[i][x2]->data != 0)
		{
			cout << "x = " << x2 << endl;
			cout << "y = " << i << endl;
			cout << "data = " << arr[i][x2]->data << endl;
			next->parent->data.push_back(arr[i][x2]);

		}
	}
	for (int j = Lx; j < Mx; j++)
	{
		if (arr[y2][j]->data != 0)
		{
			cout << "x = " << j << endl;
			cout << "y = " << y2 << endl;
			cout << "data = " << arr[y2][j]->data << endl;
			next->parent->data.push_back(arr[y2][j]);

		}
	}
}



Quad::Quad()
{
	for (int i = 0; i < MaxY; i++)
	{
		for (int j = 0; j < MaxX; j++)
		{
			arr[i][j] = new XY(j, i,0);
		}
	}
	rootNode = nullptr;
}

Quad::~Quad()
{
}
