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
		if (parent->rightChild == nullptr)
		{
			parent->rightChild = nNode;
			nNode->parent = parent;

			return;
		}
		FindPlace(nNode, parent->rightChild);
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

	if (nNode->rightChild != nullptr)Print(nNode->rightChild);

}

void RBT::ROB(Node* nNode)
{
	cout << nNode->RB << " -> ";

	if (nNode->leftChild != nullptr) ROB(nNode->leftChild);

	if (nNode->rightChild != nullptr)ROB(nNode->rightChild);
}

void RBT::Remove(int data)
{
	Node* rNode = RemoveSearch(data, rootNode);

	deleteChild(rNode);
}

Node* RBT::RemoveSearch(int data, Node* cNode)
{
	if (data == cNode->data) return cNode;
	else
	{
		if (data < cNode->data) RemoveSearch(data, cNode->leftChild);
		else if (data > cNode->data) RemoveSearch(data, cNode->rightChild);
	}

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
		if (gr->leftChild == n->parent) return gr->rightChild;
		else return gr->leftChild;
	}
	return nullptr;
}

Node* RBT::sibling(Node* n)
{
	if (n->parent != nullptr)
	{
		if (n == n->parent->leftChild) return n->parent->rightChild;
		else return n->parent->leftChild;
	}
	return nullptr;
}

Node* RBT::LEAF(Node* n)
{
	if (n->leftChild == nullptr && n->rightChild == nullptr)
		return n;
	else return nullptr;
}

#pragma endregion
#pragma region rotate
void RBT::rotate_left(Node* n)
{
	Node* c = n->rightChild;
	Node* p = n->parent;

	if (c->leftChild != NULL)
		c->leftChild->parent = n;

	n->rightChild = c->leftChild;
	n->parent = c;
	c->leftChild = n;
	c->parent = p;

	if (p != NULL) {
		if (p->leftChild == n)
			p->leftChild = c;
		else
			p->rightChild = c;
	}
	if (p == NULL) rootNode = c;
}
void RBT::rotate_Right(Node* n)
{
	Node* c = n->leftChild;
	Node* p = n->parent;

	if (c->rightChild != NULL)
		c->rightChild->parent = n;

	n->leftChild = c->rightChild;
	n->parent = c;
	c->rightChild = n;
	c->parent = p;

	if (p != NULL) {
		if (p->rightChild == n)
			p->rightChild = c;
		else
			p->leftChild = c;
	}

	if (p == NULL) rootNode = c;

}

#pragma endregion
#pragma region insert
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

	if ((n == n->parent->rightChild) && (n->parent == g->leftChild)) {
		rotate_left(n->parent);

		n = n->leftChild;
	}
	else if ((n == n->parent->leftChild) && (n->parent == g->rightChild)) {
		rotate_Right(n->parent);
		n = n->rightChild;
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

void RBT::replace(Node* n, Node* child)
{
	child->parent = n->parent;
	if (n->parent->leftChild == n)
		n->parent->leftChild = child;
	else n->parent->rightChild = child;
}

void RBT::deleteChild(Node* n)
{
	Node* child = isLeaf(n->rightChild) ? n->leftChild : n->rightChild;
	replace(n, child);
	if (n->RB = true)
	{
		if (child->RB = false)
			child->RB = true;
		else delete_case1(child);
	}
	free(n);
}

bool RBT::isLeaf(Node* n)
{
	if (LEAF(n)) return true;
	else return false;
}
#pragma region delete
void RBT::delete_case1(Node* n)
{
	if (n->parent != nullptr)
		delete_case2(n);

}

void RBT::delete_case2(Node* n)
{
	Node* s = sibling(n);

	if (s->RB == false)
	{
		n->parent->RB = false;
		s->RB = true;
		if (n == n->parent->leftChild)
			rotate_left(n->parent);
		else rotate_Right(n->parent);
	}

	delete_case3(n);
}

void RBT::delete_case3(Node* n)
{
	Node* s = sibling(n);

	if ((n->parent->RB == true) &&
		(s->RB == true) &&
		(s->leftChild->RB == true) &&
		(s->rightChild->RB == true))
	{
		s->RB = false;
		delete_case1(n->parent);
	}
	else
		delete_case4(n);
}

void RBT::delete_case4(Node* n)
{
	Node* s = sibling(n);

	if ((n->parent->RB == false) &&
		(s->RB == true) &&
		(s->leftChild->RB == true) &&
		(s->rightChild->RB == true))
	{
		s->RB = false;
		n->parent->RB = true;
	}
	else
		delete_case5(n);
}

void RBT::delete_case5(Node* n)
{
	Node* s = sibling(n);

	if (s->RB == true) {
		if ((n == n->parent->leftChild) &&
			(s->rightChild->RB == true) &&
			(s->leftChild->RB == false)) {
			s->RB = false;
			s->leftChild->RB = true;
			rotate_Right(s);
		}
		else if ((n == n->parent->rightChild) &&
			(s->leftChild->RB == true) &&
			(s->rightChild->RB == false)) {
			s->RB = false;
			s->rightChild->RB = true;
			rotate_left(s);
		}
	}
	delete_case6(n);
}

void RBT::delete_case6(Node* n)
{
	Node* s = sibling(n);

	s->RB = n->parent->RB;
	n->parent->RB = true;

	if (n == n->parent->leftChild) {
		s->rightChild->RB = true;
		rotate_left(n->parent);
	}
	else {
		s->leftChild->RB = true;
		rotate_Right(n->parent);
	}

}
#pragma endregion

RBT::RBT()
{
	rootNode = nullptr;
}

RBT::~RBT()
{
}
