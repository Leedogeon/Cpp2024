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
	void Clear(); //data,count 초기화
	int Count(); //count 체크
	bool IsEmpty();
	bool Push(int _data); //값넣기
	int Pop(); //값빼기
	int Check();
public:
	Stack(); //생성자
};

