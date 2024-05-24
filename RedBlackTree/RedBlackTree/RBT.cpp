#include "RBT.h"

void RBT::AddNode(int data)
{
	Node* nNode = createNode(data);
	nNode->RB = false;
	if (rootNode == nullptr)
	{
		rootNode = nNode;
		case1(nNode);
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
	case2(nNode);
	
	
}





Node* RBT::createNode(int data)
{
	Node* nNode = new Node(data,false,nullptr,nullptr,nullptr);
	return nNode;
}

void case1(struct Node* n)
{
	if (n->parent == nullptr)
		n->RB = true;

	return;
}
void case2(struct Node* n)
{
	if (n->parent->RB = true)
		return;
	
	case3(n);
}
void case3(struct Node* n)
{
	//n->parent->RB == false;
	Node* uc = uncle(n);
	Node* pr = n->parent;
	Node* gr = grand(n);
	if (uc != nullptr && uc->RB == false)
	{
		!uc->RB;
		!pr->RB;
		!gr->RB;
		case1(gr);
	}
	else
	{
		case4(n);
	}

}
void case4(struct Node* n)
{
	//n->parent->RB == false;
	//uc.RB == true;
	Node* pr = n->parent;
	Node* gr = grand(n);

	if (n = pr->rightChid && pr = gr->leftChild)
	{
		gr->leftChild = n;
		n->leftChild = pr;
	}
	else if (n = pr->leftChild && pr = gr->rightChid)
	{
		gr->rightChid = n;
		n->rightChid = pr;
	}
	case5(pr);
}
void case5(struct Node* n)
{
	Node* pr = n->parent;
	Node* gr = grand(n);
	


}



RBT::RBT()
{
	rootNode = nullptr;
}

RBT::~RBT()
{
}
