#pragma once

#include "stack.h"
#include "queue.h"

struct Node
{
	int data;
	Node* next;
	int cnt;
};

class Graph
{
private:
	int count;
	bool* vertexs;
	Node** graph;
public:
	void InitializeGraph(int nodeCount);
	void AddEdge(int from, int to);
	void DeleteEdge(int node, int deleteEdge);
	void ShowGraphEdge(int node);
	bool visitVertex(int node);
	void BreadthFirstSerch(int node); // ≥–¿Ã≈Ωªˆ
	void DepthFirstSerch(int node); //±Ì¿Ã≈Ωªˆ
private:
	Node* CreateNode(int data);
	void change(int _base, Node* _cng);
public:
	Graph();
	~Graph();
};

