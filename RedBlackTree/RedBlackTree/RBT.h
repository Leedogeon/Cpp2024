#pragma once
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

struct Node* grand(struct Node *n)
{
	if (n->parent != nullptr && n != nullptr)
	{
		return n->parent->parent;
	}
	return nullptr;
}
struct Node* uncle(struct Node* n)
{
	Node* gr = grand(n);
	if (gr != nullptr)
	{
		if (gr->leftChild == n->parent) return gr->rightChid;
		else return gr->leftChild;
	}
	return nullptr;
}

class RBT
{
public:
	Node* rootNode;
	void AddNode(int data);
	void FindPlace(Node* nNode,Node* parent);
	bool BigLess(Node* nNode, Node* parent);
	void Change(Node* nNode);
private:
	Node* createNode(int data);
	void case1(struct Node* n);
	void case2(struct Node* n);
	void case3(struct Node* n);
	void case4(struct Node* n);
	void case5(struct Node* n);



public:
	RBT();
	~RBT();
};

