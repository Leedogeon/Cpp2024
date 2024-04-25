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

    cout << "cont = "<< graph[from][0].count << endl;
    if (graph[from][0].count == 0)
    {
        graph[from]->next = graph[to];
        graph[from]->count++;
        return;
    }


    int count = graph[from][0].count;

    Node* cur = new Node[count + 1];
        for (int i = 0; i < count; i++)
        {
            cur[i].data = graph[from][i].data;
            cur[i].count = count + 1;
            cur[i].next = nullptr;
            cur[i].next = graph[from][i].next;

        }
        graph[from] = cur;
        graph[from][count].next = graph[to];
            
}

void Graph::DeleteEdge(int node, int deleteEdge)
{
    if (graph[node][0].count == 0) return;
    
    int count = graph[node][0].count;
    for (int i = 0; i< count; i++)
    {
        if (graph[node][i].next == graph[deleteEdge])
        {
            Node* cur = new Node[count - 1];
            int temp = 0;
            for (int j = 0; j < count; j++)
            {
                if (i == j)
                {
                    temp++;
                    
                }
                cur[j].data = graph[node][0].data;
                cur[j].count = count - 1;
                cur[j].next = nullptr;
                cur[j].next = graph[node][j+temp].next;
            }
            graph[node] = cur;
            break;
        }
    }

}

void Graph::ShowGraphEdge(int node)
{
    int cnt = graph[node][0].count;
    cout << "cnt = " << cnt << endl;
    
    cout << graph[node]->data << " ";

    for (int i = 0; i<cnt; i++)
    {
        if (graph[node][i].next == nullptr) break;
        cout << graph[node][i].next->data << " ";

    }
    cout << endl;
    
    

}

Node* Graph::CreateNode(int _data)
{
    Node* nNode = new Node;
    nNode->data = _data;
    nNode->next = nullptr;
    nNode->count = 0;
    
    return nNode;
}

Graph::Graph()
{
    graph = nullptr;

}

Graph::~Graph()
{
}
