#include "HashMap.h"

void HashMap::Add(int _key, int value)
{
    Node* nNode = new Node;
    nNode->key = _key;
    nNode->data = value;
    nNode->hashNext = nullptr;

    if (table[_key % TABLE_SIZE] == nullptr)
    {
        table[_key % TABLE_SIZE] = nNode;
    }
    else
    {
        Node* cur = table[_key % TABLE_SIZE];
        if (cur->key == _key) return;

        while (cur->hashNext != nullptr)
        {
            cur = cur->hashNext;
            if (cur->key == _key) return;
        }
        cur->hashNext = nNode;
    }
}

int HashMap::GetValue(int _key)
{
    if (table[_key%TABLE_SIZE] == nullptr) return 0;
    int res = 0;
    Node* cur = table[_key % TABLE_SIZE];
    for (int i = 0;; i++)
    {
        if (cur->key == _key)
        {
            res = cur->data;
            break;
        }

        if (cur->hashNext == nullptr) break;
        cur = cur->hashNext;
    }
    return res;
}

void HashMap::Remove(int _key)
{
    if (table[_key % TABLE_SIZE] == nullptr) return;

    Node* cur = table[_key % TABLE_SIZE];
    Node* prev = table[_key % TABLE_SIZE];
    for (int i = 0;; i++)
    {
        if (cur->key == _key)
        {
            if (cur == table[_key % TABLE_SIZE])
            {
                if (cur->hashNext != nullptr)
                {
                    table[_key % TABLE_SIZE] = cur->hashNext;
                    delete cur;
                    cur = nullptr;
                }
                else
                {
                    delete table[_key % TABLE_SIZE];
                    table[_key % TABLE_SIZE] = nullptr;
                }
               
            }

            else
            {
                if (cur->hashNext != nullptr)
                {
                    prev->hashNext = cur->hashNext;
                    
                }
                else
                {
                    
                    prev->hashNext = nullptr;
                }
                delete cur;
                cur = nullptr;
               
            }
            break;
        }

        if (cur->hashNext == nullptr) break;
        cur = cur->hashNext;
        prev->hashNext = cur;
    }
}

int HashMap::Count()
{
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] != nullptr)
        {
            Node* cur = table[i];
            while (cur != nullptr)
            {
                count++;
                cur = cur->hashNext;
            }
        }
    }

    return count;
}

void HashMap::Clear()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] != nullptr)
        {
            Node* cur = table[i];
            
            while (cur->hashNext != nullptr)
            {
                Node* next = cur->hashNext;
                cur->hashNext = next->hashNext;
                delete next;
                next = nullptr;
            }

            delete cur;
            cur = nullptr;
        }
    }
}

void HashMap::View(int _num)
{
    if (table[_num] != nullptr)
    {
        Node* cur = table[_num];
        for (int i = 0;; i++)
        {
            cout << cur->data << endl;
            if (cur->hashNext == nullptr) break;
            cur = cur->hashNext;
        }
    }

}

HashMap::HashMap()
{
    table = new Node * [TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = nullptr;
    }
}

HashMap::~HashMap()
{
    Clear();
    delete[] table;
}
