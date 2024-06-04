#pragma once
#include <iostream>
#include <queue>
#include<vector>
#include <list>
#include<map>
#define Max 7
using namespace std;

struct Node
{
	int data;
	Node* next;
	int pio;
	int cnt;
};

struct FromTo
{
	int from;
	int to;
	int pio;

	FromTo(int _from, int _to, int _pio)
		:from(_from),to(_to),pio(_pio) {};

};

struct Group
{
	list<FromTo> data;
	bool linked = false;
};

struct COM
{
	bool operator()(FromTo a, FromTo b)
	{
		if (a.pio > b.pio)
			return true;
		else return false;
	}
};

class MST
{
private:
	int count;
	bool* vertexs;
	Node** graph;
	map<int, int> dis;
	map<int, int> vs;
	list<FromTo> FT;
	priority_queue<FromTo, vector<FromTo>, COM> pFT;
	Group* gr[Max];

public:
	void Init(int nodeCount);
	void AddEdge(int from, int to, int pio);
	bool visitVertex(int node);
	void BreadthFirstSerch();
	void ShowGraphEdge(int node);
private:
	Node* createNode(int data);
	void change(int _base, Node* _cng);
public:
	MST();
	~MST();
};