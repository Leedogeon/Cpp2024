#include "BinaryTree.h"
void BinaryTree::AddNode(int _data)
{
    Node* nNode = CreateNode(_data);

    if (rootNode == nullptr)
    {
        rootNode = nNode;
    }
    else
    {
        Node* cur = rootNode;
        InsertNode(cur, nNode);
    }
}

void BinaryTree::RemoveNode(int _data)
{
    Node* cur = rootNode;
    DeleteNode(cur,_data);
}

void BinaryTree::PrintAll()
{
    InOrder(rootNode);
}

Node* BinaryTree::CreateNode(int _data)
{
    Node* nNode = new Node;
    nNode->data = _data;
    nNode->left = nullptr;
    nNode->right = nullptr;
    return nNode;
}

void BinaryTree::InsertNode(Node* tree, Node* newNode)
{
    Node* cur = tree;
    if (tree->data < newNode->data)
    {
        if (tree->right == nullptr) tree->right = newNode;
        else InsertNode(cur->right, newNode);
    }
    else
    {
        if (tree->left == nullptr) tree->left = newNode;
        else InsertNode(cur->left, newNode);
    }
}

Node* BinaryTree::DeleteNode(Node* tree, int _data)
{
    Node* cur = tree;
    if (cur->data == _data)
    {
        if (cur->left == nullptr && cur -> right == nullptr)
        {
            
        }
        else
        {
            if (cur->left != nullptr)
            {
                if (cur->left->right != nullptr)
                {
                    cur->left->right->right = cur->right;
                }
                else
                {
                    cur->left->right = cur->right;
                }
                tree = cur->left;
            }
            else
            {
                tree = cur->right;
            }
            if (cur == rootNode) rootNode = tree;

            delete cur;
            cur = nullptr;
            }

    }
    else
    {
        if (cur->data < _data)
        {
            cur -> right = DeleteNode(cur->right, _data);
        }
        else
        {
            cur -> left = DeleteNode(cur->left, _data);
        }
    }

    return tree;
}

Node* BinaryTree::FindMin(Node* root)
{
    if (root->left != nullptr)
    {
        FindMin(root->left);
        return FindMin(root->left);
    } 
    else if (root->left == nullptr)
    {   
        return root;
    }
}

void BinaryTree::InOrder(Node* root)
{
    if (root->left != nullptr) InOrder(root->left);
    cout << root->data << endl;
    if (root->right != nullptr) InOrder(root->right);
    
}

BinaryTree::BinaryTree()
{
    rootNode = nullptr;
}

BinaryTree::~BinaryTree()
{
    if (rootNode != nullptr)
    {
        while (rootNode != nullptr)
        {
            Node* cur = FindMin(rootNode);
            cout << "c = " << FindMin(rootNode)->data << endl;;
            RemoveNode(cur->data);
        }
        
    }
    delete rootNode;
    rootNode = nullptr;
}
