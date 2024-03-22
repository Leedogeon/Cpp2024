#pragma once
#include<iostream>
using namespace std;
class GameManager
{
private:
	static GameManager* instance;
public:
	static GameManager* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new GameManager;
		}

		return instance;
	}
public:
	void HelloWorld()
	{
		cout << "Hello world" << endl;
	}
};


