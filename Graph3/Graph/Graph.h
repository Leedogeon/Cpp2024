#pragma once
#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
	int count;
};

class Graph
{
private:
	Node** graph;
public:
	void InitializeGraph(int nodeCount);
	void AddEdge(int from, int to);
	void DeleteEdge(int node, int deleteEdge);
	void ShowGraphEdge(int node);
private:
	Node* CreateNode(int _data);
	void change(int _base,Node* _cng);
public:
	Graph();
	~Graph();
};

