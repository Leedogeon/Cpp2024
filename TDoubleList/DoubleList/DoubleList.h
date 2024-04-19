#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	T data;
	Node* left;
	Node* right;
};

template <typename T>
class DoubleList
{
public:
	Node* head;
	Node* tail;
	int count;
public:
	void Push_Back(T _data);
	void Push_Front(T _data);
	Node* CreateNode(T _data);
	int Pop_Back();
	int Pop_Front();
	bool Empty();
	void Clear();
	void Insert(int _index, T _data);
	void Insert(int _index, int _count, T _data); // 해당되는 데이터를 count만큼
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

