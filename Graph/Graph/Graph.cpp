#include "Graph.h"

void Graph::InitializeGraph(int nodeCount)
{
    graph = new Node* [nodeCount];
    
    for (int i = 0; i < nodeCount; i++)
    {
        graph[i] = CreateNode(i + 1);
    }
}

void Graph::AddEdge(int from, int to)
{
    if (graph[from]->next = nullptr)
    {
        graph[from]->next[0] = *graph[to];
    }
    cout << graph[from]->next[0].data << endl;
}

void Graph::DeleteEdge(int node, int deleteEdge)
{

}

void Graph::ShowGraphEdge(int node)
{
}

Node* Graph::CreateNode(int data)
{
    Node* nNode = new Node;
    nNode->data = data;
    nNode->next = new Node[10];
    nNode->next = nullptr;
    
    return nNode;
}

Graph::Graph()
{
    graph = nullptr;

}

Graph::~Graph()
{
}
