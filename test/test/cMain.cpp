#pragma once
#include <iostream>
#include<list>
using namespace std;

#define MaxX 256
#define MaxY 256

struct XY
{
	int x;
	int y;
	int data;
	XY(int _x, int _y, int _data) : x(_x), y(_y), data(_data) {};

};


int main()
{
	list<XY*> data;
	XY* a = new XY(1,2,3);
	data.push_back(a);

	cout << data.front()->data<< endl;
	
}