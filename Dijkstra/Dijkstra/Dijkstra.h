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
class Dijkstra
{
private:
	int count;
	bool* vertexs;
	Node** graph;
	map<int, int> dis;
public:
	void Init(int nodeCount);
	void AddEdge(int from, int to, int pio);
	bool visitVertex(int node);
	void BreadthFirstSerch(int node);
	void ShowGraphEdge(int node);
private:
	Node* createNode(int data);
	void Breadth(int node, queue<int> &que, queue<int> &pque);
	void change(int _base, Node* _cng);
	void FindNext(int front,queue<int>& que, queue<int> &pque);
public:
	Dijkstra();
	~Dijkstra();
};

