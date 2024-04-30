#pragma once
#include<iostream>
using namespace std;
class Stack
{
private:
	int* data;
	int count;
public:
	void Clear(); //data,count 초기화
	int Count(); //count 체크
	bool IsEmpty();
	void Push(int _data); //값넣기
	int Pop(); //값빼기
	bool Check(int _data);
	void PrintAll();
public:
	Stack(); //생성자
	~Stack();
};

