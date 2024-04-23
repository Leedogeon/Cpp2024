#include "HashMap.h"

void HashMap::Add(int _key, int value)
{
    if (Count() == TABLE_SIZE) return;

    Node* nNode = new Node;
    nNode->key = _key;
    nNode->data = value;
    while (table[_key % TABLE_SIZE] == nullptr)
    {
        _key += 1;

    }
    table[_key % TABLE_SIZE] = nNode;
}

int HashMap::GetValue(int _key)
{
    int res;
    for (int i = _key % TABLE_SIZE;; i++)
    {
        if (table[_key % TABLE_SIZE]->key == _key)
        {
            res = table[_key % TABLE_SIZE]->data;
            break;
        }
            
    }
    return res;
}

void HashMap::Remove(int _key)
{
    Node** nTable = table;
    

}

int HashMap::Count()
{
    return 0;
}

void HashMap::Clear()
{
    Node** nTable = table;
    
}

HashMap::HashMap()
{
    table = new Node*[TABLE_SIZE];

}

HashMap::~HashMap()
{
    Clear();
    delete table;
    table = nullptr;
}
