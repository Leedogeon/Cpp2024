#include "RBT.h"

void RBT::AddNode(int data)
{
	Node* nNode = createNode(data);
	nNode->RB = false;
	if (rootNode == nullptr)
	{
		rootNode = nNode;
		insert_case1(nNode);
		return;
	}
	FindPlace(nNode, rootNode);
	insert_case2(nNode);

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

void RBT::Print(Node* nNode)
{
	cout << nNode->data << " -> ";

	if (nNode->leftChild != nullptr) Print(nNode->leftChild);
	
	if (nNode->rightChid != nullptr)Print(nNode->rightChid);

}

void RBT::ROB(Node* nNode)
{
	cout << nNode->RB << " -> ";

	if (nNode->leftChild != nullptr) ROB(nNode->leftChild);

	if (nNode->rightChid != nullptr)ROB(nNode->rightChid);
}

Node* RBT::createNode(int data)
{
	Node* nNode = new Node(data, false, nullptr, nullptr, nullptr);
	return nNode;
}

#pragma region grand,uncle
Node* RBT::grand(Node* n)
{
	if (n->parent != nullptr && n != nullptr)
	{
		return n->parent->parent;
	}
	return nullptr;
}

Node* RBT::uncle(Node* n)
{
	Node* gr = grand(n);
	if (gr != nullptr)
	{
		if (gr->leftChild == n->parent) return gr->rightChid;
		else return gr->leftChild;
	}
	return nullptr;
}

#pragma endregion
#pragma region rotate
void RBT::rotate_left(Node* n)
{
	Node* c = n->rightChid;
	Node* p = n->parent;

	if (c->leftChild != NULL)
		c->leftChild->parent = n;

	n->rightChid = c->leftChild;
	n->parent = c;
	c->leftChild = n;
	c->parent = p;

	if (p != NULL) {
		if (p->leftChild == n)
			p->leftChild = c;
		else
			p->rightChid = c;
	}
	if (p == NULL) rootNode = c;
}
void RBT::rotate_Right(Node* n)
{
	Node* c = n->leftChild;
	Node* p = n->parent;

	if (c->rightChid != NULL)
		c->rightChid->parent = n;

	n->leftChild = c->rightChid;
	n->parent = c;
	c->rightChid = n;
	c->parent = p;

	if (p != NULL) {
		if (p->rightChid == n)
			p->rightChid = c;
		else
			p->leftChild = c;
	}

	if (p == NULL) rootNode = c;

}

#pragma endregion
#pragma region case
void RBT::insert_case1(Node* n)
{

	if (n->parent == NULL)
		n->RB = true;
	else
		insert_case2(n);
}
void RBT::insert_case2(Node* n)
{
	if (n->parent->RB == true)
		return; /* Tree is still valid */
	else
		insert_case3(n);
}
void RBT::insert_case3(Node* n)
{
	Node* u = uncle(n), * g;

	if ((u != NULL) && (u->RB == false)) {
		n->parent->RB = true;
		u->RB = true;
		g = grand(n);
		g->RB = false;
		insert_case1(g);
	}
	else {
		insert_case4(n);
	}
}
void RBT::insert_case4(Node* n)
{
	Node* g = grand(n);

	if ((n == n->parent->rightChid) && (n->parent == g->leftChild)) {
		rotate_left(n->parent);
		
		n = n->leftChild;
	}
	else if ((n == n->parent->leftChild) && (n->parent == g->rightChid)) {
		rotate_Right(n->parent);
		n = n->rightChid;
	}
	insert_case5(n);
}
void RBT::insert_case5(Node* n)
{
	Node* g = grand(n);

	n->parent->RB = true;
	g->RB = false;
	if (n == n->parent->leftChild)
		rotate_Right(g);
	else
		rotate_left(g);
}
#pragma endregion


RBT::RBT()
{
}

RBT::~RBT()
{
}
