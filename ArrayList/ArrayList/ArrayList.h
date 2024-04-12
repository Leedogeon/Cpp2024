#pragma once
#include <iostream>

using namespace std;

class ArrayList
{
public:
	int* data;
	int count;
public:
	//Ãß°¡
	void AddNode(int _data);
	void InsertNode(int _index, int _data);
	void InsertNode(int _index, int _count, int _data);
	void UpdateNode(int _index, int _data);
	void DeleteNodeData(int _data);
	void DeleteIndex(int _index);
	void ClearAllNode();
	int GetNodeData(int _index);
	int GetListSize();
	bool IsEmpty();
	void PrintAll();
public:
	ArrayList();
	~ArrayList();
};

