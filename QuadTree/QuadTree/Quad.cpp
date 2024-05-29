#include "Quad.h"

void Quad::AddData(int x, int y, int data)
{
	arr[y][x]->x = x;
	arr[y][x]->x = y;
	arr[y][x]->data = data;
}

void Quad::FindAll()
{
	Node* nNode = createNode();
	if (rootNode == nullptr) rootNode = nNode;

	FindData(nNode, MaxX, MaxY, 0, 0);
}








Node* Quad::createNode()
{
	Node* nNode = new Node(nullptr, nullptr, nullptr, nullptr, nullptr);
	return nNode;
}

void Quad::FindData(Node* nNode,int Mx, int My, int Lx, int Ly)
{
	FindUL(nNode,Mx,My,Lx,Ly);
	FindUR(nNode, Mx, My, Lx, Ly);
	FindDL(nNode, Mx, My, Lx, Ly);
	FindDR(nNode, Mx, My, Lx, Ly);
}

void Quad::FindUL(Node* nNode, int Mx, int My, int Lx, int Ly)
{
	int x1 = (Mx - Lx) / 2;
	int y1 = (My - Ly) / 2;
	int x2 = (x1 - Lx) / 2;
	int y2 = My - (My - y1) / 2;
	if (Mx == x1 && My == y1) return;
	for (int i = Ly; i < My; i++)
	{
		if (arr[i][x2]->data != 0) nNode->UL->data->push_back(arr[i][x2]);
	}
	for (int j = Lx; j < Mx; j++)
	{
		if (arr[y2][j]->data != 0) nNode->UL->data->push_back(arr[y2][j]);
	}

	Node* next = createNode();
	next->parent = nNode;

	FindData(next,Mx, My, x1, y1);
}

void Quad::FindUR(Node* nNode, int Mx, int My, int Lx, int Ly)
{
	int x1 = (Mx - Lx) / 2;
	int y1 = (My - Ly) / 2;
	int x2 = Mx - (Mx - x1) / 2;
	int y2 = My - (My - y1) / 2;
	if (Mx == x1 && My == y1) return;
}

void Quad::FindDL(Node* nNode, int Mx, int My, int Lx, int Ly)
{
	int x1 = (Mx - Lx) / 2;
	int y1 = (My - Ly) / 2;
	int x2 = (x1 - Lx) / 2;
	int y2 = y1 - (y1-Lx) / 2;
	if (Mx == x1 && My == y1) return;

}
void Quad::FindDR(Node* nNode, int Mx, int My, int Lx, int Ly)
{
	int x1 = (Mx - Lx) / 2;
	int y1 = (My - Ly) / 2;
	int x2 = Mx - (Mx - x1) / 2;
	int y2 = y1 - (y1 - Lx) / 2;
	if (Mx == x1 && My == y1) return;

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
