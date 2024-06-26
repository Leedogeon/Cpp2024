#pragma once
#include <iostream>
#include <queue>
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
class MST
{
private:
	int count;
	bool* vertexs;
	Node** graph;
	map<int, int> dis;
	map<int, int> vs;
public:
	void Init(int nodeCount);
	void AddEdge(int from, int to, int pio);
	bool visitVertex(int node);
	void BreadthFirstSerch(int node);
	void ShowGraphEdge(int node);
private:
	Node* createNode(int data);
	void Breadth(int node, queue<int>& pque);
	void change(int _base, Node* _cng);
public:
	MST();
	~MST();
};
