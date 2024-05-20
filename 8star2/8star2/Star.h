#pragma once
#include<iostream>
#include<list>
using namespace std;
#define MaxX 10
#define MaxY 7

struct Node
{
	int x;
	int y;
	int find;
	int Mdis;
	int move;
	int res;
	
	Node* parent;
};
class Star
{
public:
	Node arr[MaxY][MaxX] = {};
	list<Node> lb;

public:
	void Init(int x, int y);
	void Hole(int x, int y);
	void FindDisT(int nX, int nY, int lX, int lY , Node cNode);
	void FindDisX(int nX, int nY, int lX, int lY, Node cNode);
	Star();
	~Star();
};

