#pragma once
#include<iostream>
#include <queue>
#include <vector>
using namespace std;
#define MaxX 30
#define MaxY 30
struct Node
{
	int x;
	int y;
	int dis;
	int move;
	int res;
	int find;
	Node* parent;
};

struct COM
{
	bool operator()(Node* a, Node* b)
	{
		if (a->res != b->res)
			return a->res > b->res;
		else return a->dis > b->dis;
	}
};

class star
{
public:
	Node arr[MaxY][MaxX] = {};
	
	priority_queue<Node*,vector<Node*>,COM> qN;
public:
	void Start(Node* sNode);
	void End(Node* fNode);
	Node* NewNode(int y, int x);
	void Hole(Node* xNode);
	Node* FindDis(Node* nNode, Node* fNode);
	
	void eStart(Node* esNode);

private:
	void Result(Node* cNode, Node* fNode, int move);
public:
	star();
	~star();
};

