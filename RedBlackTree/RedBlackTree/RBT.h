#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int data;
	bool RB;
	Node* parent;
	Node* leftChild;
	Node* rightChid;

	Node(int _data, bool _RB, Node* _parent, Node* _leftChild, Node* rightChild)
		:data(_data), RB(false), parent(nullptr), leftChild(nullptr), rightChid(nullptr) {}
};

class RBT
{
public:
	Node* rootNode;
	void AddNode(int data);
	void FindPlace(Node* nNode, Node* parent);
	bool BigLess(Node* nNode, Node* parent);
	void Print(Node* nNode);
	void ROB(Node* nNode);

private:
	Node* createNode(int data);
	Node* grand(Node* n);
	Node* uncle(Node* n);
	void rotate_left(Node* n);
	void rotate_Right(Node* n);
	void insert_case1(Node* n);
	void insert_case2(Node* n);
	void insert_case3(Node* n);
	void insert_case4(Node* n);
	void insert_case5(Node* n);
public:
	RBT();
	~RBT();
};