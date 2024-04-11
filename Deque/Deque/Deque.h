#pragma once
#include <iostream>
using namespace std;

class Deque
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
	int Dequeue(int _num);
	void Check();
public:
	Deque();
	~Deque();
};

