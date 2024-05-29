#pragma once
#include <iostream>
#include<list>
using namespace std;

#define MaxX 256
#define MaxY 256

struct XY
{
	int x;
	int y;
	int data;
	XY(int _x, int _y,int _data) : x(_x), y(_y),data(_data) {};
	
};

struct Node
{
	list<XY*> data[MaxX / 4] = {};
	Node* parent;
	Node* UL;
	Node* UR;
	Node* DL;
	Node* DR;

	Node(Node* _parent,Node* _UL, Node* _UR, Node* _DL, Node* _DR) : parent(nullptr),UL(nullptr), UR(nullptr), DL(nullptr), DR(nullptr) {};
};


class Quad
{
public:
	XY* arr[MaxY][MaxX];
	Node* rootNode;

	void AddData(int x, int y, int data);
	void FindAll();
private:
	Node* createNode();

	void FindData(Node* nNode, int Mx, int My, int Lx, int Ly);
	void FindUL(Node* nNode, int Mx,int My, int Lx,int Ly);
	void FindUR(Node* nNode, int Mx, int My, int Lx, int Ly);
	void FindDL(Node* nNode, int Mx, int My, int Lx, int Ly);
	void FindDR(Node* nNode, int Mx, int My, int Lx, int Ly);

public:
	Quad();
	~Quad();
};

