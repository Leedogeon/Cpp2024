#pragma once
#include<iostream>
using namespace std;
#define MaxCount 5
template <typename T>
class Stack
{
private:
	T* data;
	int count;
public:
	bool IsEmpty();
	void Push(T _data); //���ֱ�
	int Check();
public:
	Stack(); //������
	~Stack();
};