#pragma once
#include<iostream>
using namespace std;
#define MaxCount 5
class Stack
{
private:
	int *data;
	int count;
public:
	void Clear(); //data,count �ʱ�ȭ
	void Count(); //count üũ
	bool IsEmpty();
	void Push(int _data); //���ֱ�
	int Pop(); //������
	int Check();
public:
	Stack(); //������
	~Stack();
};

