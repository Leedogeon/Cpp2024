#pragma once
#include<iostream>
using namespace std;
class Stack
{
private:
	int* data;
	int count;
public:
	void Clear(); //data,count �ʱ�ȭ
	int Count(); //count üũ
	bool IsEmpty();
	void Push(int _data); //���ֱ�
	int Pop(); //������
	bool Check(int _data);
	void PrintAll();
public:
	Stack(); //������
	~Stack();
};

