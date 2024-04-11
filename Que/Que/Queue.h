#pragma once
#include <iostream>
using namespace std;

class Queue
{
public:
	int* data;
private:
	int count;
public:
	void Clear();
	int Count();
	bool IsEmpty();
	void Enqueue(int _data);
	int Dequeue();
	void Check();
public:
	Queue();
	~Queue();
};

