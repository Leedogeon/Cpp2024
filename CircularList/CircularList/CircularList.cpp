#include "CircularList.h"

void CircularList::AddNode(int _data)
{
    Node* nNode = new Node;
    nNode->data = _data;
    if (IsEmpty())
    {
        tail = nNode;
        nNode->next = nNode;
    }
    else
    {
        nNode->next = tail->next;
        tail->next = nNode;
        tail = nNode;
    }
}

void CircularList::InsertNode(int _index, int _data)
{
    Node* nNode = new Node;
    nNode->data = _data;
    if (IsEmpty())
    {
        tail = nNode;
        nNode->next = nNode;
        return;
    }
    Node* cur = tail;
    
    for (int i = 0; i < _index; i++)
    {
        cur = cur->next;
    }
    nNode->next = cur->next;
    cur->next = nNode;
    if (cur == tail)
    {
        tail = nNode;
    }
}

void CircularList::UpdateNode(int _index, int _data)
{
    if (IsEmpty()) return;

    Node* cur = tail;
    for (int i = 0; i < _index; i++)
    {
        cur = cur->next;
    }
    cur->data = _data;
}

void CircularList::DeleteNodeData(int _data)
{
    if (IsEmpty()) return;
    
    if (tail->next == tail)
    {
        delete tail;
        tail = nullptr;
        return;
    }

    Node* cur = tail;
    Node* dNode = nullptr;
    bool chk = false;
    while (chk != true)
    {
        if (cur->next->data == _data)
        {            
            dNode = cur->next;
            if (cur->next == tail)
            {
                tail = cur;
            }
            cur->next = cur->next->next;
            chk = true;
            delete dNode;
        }

        if (cur->next == tail) chk = true;

        cur = cur->next;

    }
}

void CircularList::DeleteIndex(int _index)
{
    if (IsEmpty()) return;

    if (tail->next == tail)
    {
        delete tail;
        tail = nullptr;
        return;
    }
    
    Node* cur = tail;
    Node* dNode = nullptr;
    while (cur->next != tail)
    {
        cur = cur->next;
    }
    for (int i = 0; i < _index; i++)
    {
        cur = cur->next;
    }
    dNode = cur->next;
    if (cur->next == tail) tail = cur;
    cur->next = cur->next->next;
    delete dNode;
}

void CircularList::ClearAllNode()
{
    while (tail->next != tail)
    {
        Node* dNode = tail->next;
        tail->next = tail->next->next;
        delete dNode;
    }
    delete tail;
    tail = nullptr;
}

int CircularList::GetNodeData(int _index)
{
    if (IsEmpty())
    {
        cout << "data가 없습니다 : ";
        return 0;
    }
    Node* cur = tail;

    for (int i = 0; i < _index; i++)
    {
        cur = cur->next;
    }

    return cur->data;
}

bool CircularList::IsEmpty()
{
    if (tail == nullptr) return true;
    else return false;
}

void CircularList::PrintAll()
{
    if (IsEmpty())
    {
        cout << "data가 없습니다" << endl;
        return;
    }
    if (tail == nullptr) return;
    Node* cur = tail;

    for (int i = 0;; i++)
    {
        cout << cur->data << endl;
        if (cur->next == tail) break;
        cur = cur->next;
    }
}

int CircularList::Count()
{
    if (IsEmpty()) return 0;
    int cnt = 0;
    Node* cur = tail;
    for (int i = 0;; i++)
    {
        cnt++;
        if (cur->next == tail) break;
        cur = cur->next;
    }
    return cnt;
}

CircularList::CircularList()
{
    tail = nullptr;
}

CircularList::~CircularList()
{
    while (tail->next != tail)
    {
        Node* dNode = tail->next;
        tail->next = tail->next->next;
        delete dNode;
    }
    delete tail;
    tail = nullptr;
}
