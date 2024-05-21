#pragma once
#include<iostream>
#include<list>
using namespace std;
#define MaxX 17
#define MaxY 17

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
	Node NewNode(int y, int x);
	void Hole(int x, int y);
	void FindDisT(Node nNode, int x,int y , Node cNode);
	Star();
	~Star();
};

