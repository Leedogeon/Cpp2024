#pragma once
#include<iostream>
using namespace std;
#define MaxCount 5
class Stack
{
private:
	int data[MaxCount] = {};
	int count = 0;
public:
	void Clear(); //data,count �ʱ�ȭ
	int Count(); //count üũ
	bool IsEmpty();
	bool Push(int _data); //���ֱ�
	int Pop(); //������
	int Check();
public:
	Stack(); //������
};

