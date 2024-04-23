#include "HashMap.h"

void HashMap::Add(int _key, int value)
{
    Node* nNode = new Node;
    nNode->key = _key;
    nNode->data = value;
}

int HashMap::GetValue(int _key)
{
    Node** nTable = table;
    int value;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (nTable[i]->key == _key)
            value = nTable[i]->data;
    }

    return value;
}

void HashMap::Remove(int _key)
{
    Node** nTable = table;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        nTable[i]->key == _key;
        delete nTable[i];
        nTable[i] = nullptr;
    }

}

int HashMap::Count()
{
    int count = 0;
    Node** nTable = table;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        nTable[i]->key != NULL;
        count++;
    }
    return count;
}

void HashMap::Clear()
{
    Node** nTable = table;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        delete nTable[i];
        nTable[i] = nullptr;
    }
}

HashMap::HashMap()
{
    table = nullptr;
}

HashMap::~HashMap()
{
    Clear();
    delete table;
    table = nullptr;
}
