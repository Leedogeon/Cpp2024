#include "RBT.h"

void RBT::AddNode(int data)
{
	Node* nNode = createNode(data);
	nNode->RB = false;
	if (rootNode == nullptr)
	{
		rootNode = nNode;
		nNode->RB = true;
		return;
	}
	FindPlace(nNode, rootNode);


	Change(nNode);

}

void RBT::FindPlace(Node* nNode, Node* parent)
{
	if (BigLess(nNode, parent))
	{
		if (parent->leftChild == nullptr)
		{
			parent->leftChild = nNode;
			nNode->parent = parent;

			return;
		}
		FindPlace(nNode, parent->leftChild);

	}
	else
	{
		if (parent->rightChid == nullptr) 
		{
			parent->rightChid = nNode;
			nNode->parent = parent;
			
			return;
		}
		FindPlace(nNode, parent->rightChid);
	}
}

bool RBT::BigLess(Node* nNode, Node* parent)
{
	if (nNode->data < parent->data) return true;
	return false;
}

void RBT::Change(Node* nNode)
{
	if (uncle(nNode)->RB == true)
	{

	}
}


Node* RBT::createNode(int data)
{
	Node* nNode = new Node(data,false,nullptr,nullptr,nullptr);
	return nNode;
}

RBT::RBT()
{
	rootNode = nullptr;
}

RBT::~RBT()
{
}
