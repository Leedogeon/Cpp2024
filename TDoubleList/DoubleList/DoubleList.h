#pragma once
#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

class DoubleList
{
public:
	Node* head;
	Node* tail;
	int count;
public:
	void Push_Back(int _data);
	void Push_Front(int _data);
	Node* CreateNode(int _data);
	int Pop_Back();
	int Pop_Front();
	bool Empty();
	void Clear();
	void Insert(int _index, int _data);
	void Insert(int _index, int _count, int _data); // 해당되는 데이터를 count만큼
	void DeleteNode(int _index);

public:
	void PrintAll();
public:
	DoubleList()
	{
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	~DoubleList();

};

