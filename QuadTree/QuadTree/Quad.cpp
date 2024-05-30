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
	for (auto num: cNode->data)
	{
		cout << num->data << endl;
	}
	if(cNode->UL!= nullptr)
	PrintAll(cNode->UL);
	if (cNode->UR != nullptr)
		PrintAll(cNode->UR);
	if (cNode->DL != nullptr)
		PrintAll(cNode->DL);
	if (cNode->DR != nullptr)
		PrintAll(cNode->DR);
}


Node* Quad::createNode(Node* parent)
{
	Node* nNode = new Node(parent);
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
	int x1 = Mx - (Mx - Lx) / 2;
	int y1 = My - (My - Ly) / 2;
	int x2 = Mx - (Mx - x1) / 2;
	int y2 = My - (My - y1) / 2;

	Node* next = createNode(nNode);
	nNode->UR = next;

	insertData(next, Mx, My, Lx, Ly, x2, y2);
	if (Mx - x2 == 1) return;
	FindData(next, Mx, My, x1, y1);
}

void Quad::FindDL(Node* nNode, int Mx, int My, int Lx, int Ly)
{
	int x1 = Lx + (Mx - Lx) / 2;
	int y1 = Ly + (My - Ly) / 2;
	int x2 = Lx + (x1 - Lx) / 2;
	int y2 = y1 - (y1 - Ly) / 2;

	Node* next = createNode(nNode);
	nNode->DL = next;

	insertData(next, Mx, My, Lx, Ly, x2, y2);
	if (y2 - Ly == 1) return;


	FindData(next, x1, y1, Lx, Ly);
}
void Quad::FindDR(Node* nNode, int Mx, int My, int Lx, int Ly)
{
	int x1 = Mx - (Mx - Lx) / 2;
	int y1 = Ly + (My - Ly) / 2;
	int x2 = Mx - (Mx - x1) / 2;
	int y2 = Ly + (y1 - Ly) / 2;

	Node* next = createNode(nNode);
	nNode->DR= next;

	insertData(next, Mx, My, Lx, Ly, x2, y2);
	if (y2 - Ly == 1) return;
	FindData(next, Mx, y1, x1, Ly);
}

void Quad::insertData(Node* next, int Mx, int My, int Lx, int Ly, int x2, int y2)
{


	int resX = x2 - Lx;
	int resY = y2 - Ly;
	if (resX == 1 || resY == 1)
	{
		if (arr[y2][x2]->data != 0 && arr[y2][x2]->check == false)
		{
			next->parent->data.push_back(arr[y2][x2]);
			arr[y2][x2]->check = true;
			delete(next);
		}
		return;
	}


	for (int i = Ly; i < My; i++)
	{
		if (arr[i][x2]->check == true) continue;

		if (arr[i][x2]->data != 0)
		{
			next->parent->data.push_back(arr[i][x2]);
			arr[i][x2]->check = true;
		}
	}
	for (int j = Lx; j < Mx; j++)
	{

		if (arr[y2][j]->check == true) continue;
		if (arr[y2][j]->data != 0)
		{
			next->parent->data.push_back(arr[y2][j]);
			arr[y2][j]->check = true;
		}
	}
}



Quad::Quad()
{
	for (int i = 0; i < MaxY; i++)
	{
		for (int j = 0; j < MaxX; j++)
		{
			arr[i][j] = new XY(j, i, 0 , false);
		}
	}
	rootNode = nullptr;
}

Quad::~Quad()
{
}
