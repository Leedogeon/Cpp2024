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
    if (graph[from][0].next == nullptr)
    {
        graph[from][0].next = graph[to];
    }
    else
    {
        for (int i = 1; i < 10; i++)
        {
            if (graph[from][i].next == graph[to]) break;

            if (graph[from][i].next == nullptr)
            {
                graph[from][i].next = graph[to];
                break;
            }
        }
    }
    
}

void Graph::DeleteEdge(int node, int deleteEdge)
{
    if (graph[node][0].next == nullptr) return;

    for (int i = 0;;i++)
    {
        if (graph[node][i].next == nullptr) break;


        if (graph[node][i].next == graph[deleteEdge])
        {
            for (int j = i;; j++)
            {
                if (graph[node][j + 1].next == nullptr) break;
                graph[node][j].next = graph[node][j+1].next;
                graph[node][j + 1].next = nullptr;
            }
        }
    }

}

void Graph::ShowGraphEdge(int node)
{

    cout << graph[node]->data << "->";
    for (int i = 0;; i++)
    {
        if (graph[node][i].next == nullptr) break;
        cout << graph[node][i].next->data;
        if(graph[node][i+1].next != nullptr) cout << "->";
    }
    cout << endl;
    

}

Node* Graph::CreateNode(int _data)
{
    Node* nNode = new Node[10];
    for (int i = 0; i < 10; i++)
    {
        nNode[i].data = _data;
        nNode[i].next = nullptr;
    }
    
    return nNode;
}

Graph::Graph()
{
    graph = nullptr;

}

Graph::~Graph()
{
}
