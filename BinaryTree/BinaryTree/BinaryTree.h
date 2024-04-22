#pragma once
#include <iostream>

using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int data;
};

class BinaryTree
{
public:
	Node* rootNode;
public: // �ܺο��� ȣ�� �뵵
	//��� �߰�
	void AddNode(int _data);
	//��� ����
	void RemoveNode(int _data);
	//��� ��� ���
	void PrintAll();
private: // ���� ���� �뵵 (���)
	//��� ����
	Node* CreateNode(int _data);
	//��� ����
	void InsertNode(Node* tree, Node* newNode);
	//��� ����
	Node* DeleteNode(Node* tree, int _data);
	//������ ã��
	Node* FindMin(Node* root);
	//������ ���� ȣ��
	void InOrder(Node* root);
public:
	BinaryTree();
	~BinaryTree();
};

