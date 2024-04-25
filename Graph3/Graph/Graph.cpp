#include "Graph.h"

void Graph::InitializeGraph(int nodeCount)
{
	graph = new Node * [nodeCount];
	for (int i = 0; i < nodeCount; i++)
	{
		graph[i] = CreateNode(i + 1);
	}
}

void Graph::AddEdge(int from, int to)
{

	if (graph[from][0].count == 0)
	{
		graph[from]->next = graph[to];
		graph[from]->count++;

		if (graph[to][0].count == 0)
		{
			graph[to]->next = graph[from];
			graph[to]->count++;
		}
		else
		{
			
			int tc = 0;
			Node* tcur = new Node[tc + 1];
			for (int i = 0; i < tc; i++)
			{
				tcur[i].data = graph[to][i].data;
				tcur[i].count = graph[to][0].count + 1;
				tcur[i].next = nullptr;
				tcur[i].next = graph[to][i].next;
			}
			graph[to] = tcur;
			graph[to][tc].next = graph[from];
			graph[from][0].next = graph[to];
		}
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

	int tcount = graph[to][0].count;

	if (graph[to][0].count == 0)
	{
		graph[to]->next = graph[from];
		graph[to]->count++;
		return;
	}

	Node* cur2 = new Node[tcount + 1];
	for (int i = 0; i < tcount; i++)
	{
		cur2[i].data = graph[to][i].data;
		cur2[i].count = tcount + 1;
		cur2[i].next = nullptr;
		cur2[i].next = graph[to][i].next;

	}
	graph[to] = cur2;
	graph[to][tcount].next = graph[from];
	graph[from][count].next = graph[to];
	


}

void Graph::DeleteEdge(int node, int deleteEdge)
{
	if (graph[node][0].count == 0) return;

	int cn = graph[node][0].count;
	int cd = graph[deleteEdge][0].count;
	int count = graph[node][0].count;
	
	for (int i = 0; i < cn; i++)
	{
		if (graph[node][i].next == graph[deleteEdge])
			cout << "test" << endl;
	}



	if (count == 1)
	{
		if (graph[node]->next == graph[deleteEdge])
		{
			Node* cur = new Node;
			cur->data = graph[node]->data;
			cur->next = nullptr;
			cur->count = 0;

			graph[node] = cur;

			if (graph[deleteEdge][0].count == 1)
			{
				Node* cur2 = new Node;
				cur2->data = graph[deleteEdge]->data;
				cur2->next = nullptr;
				cur2->count = 0;

				graph[deleteEdge] = cur2;
			}

			else
			{
				for (int i = 0; i < graph[deleteEdge][0].count; i++)
				{

					Node* cur2 = new Node[graph[deleteEdge][0].count - 1];
					int temp = 0;
					for (int j = 0; j < count; j++)
					{
						if (i == j)
						{
							temp++;

						}
						cur2[j].data = graph[deleteEdge][0].data;
						cur2[j].count = count - 1;
						cur2[j].next = nullptr;
						cur2[j].next = graph[deleteEdge][j + temp].next;
					}
					graph[deleteEdge] = cur2;

				}
			}

		}
		return;
	}






	for (int i = 0; i < count; i++)
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
				cur[j].next = graph[node][j + temp].next;
			}
			graph[node] = cur;
			break;
		}
	}

}

void Graph::ShowGraphEdge(int node)
{
	int cnt = graph[node][0].count;
	cout << graph[node]->data << " ";
	for (int i = 0; i < cnt; i++)
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

Node* Graph::DeleteNode(int _node)
{
	int cnt = graph[_node][0].count;
	cout << "cnt = " << cnt <<endl;

	if (cnt == 1)
	{
		Node* cur = new Node;
		cur->data = graph[_node]->data;
		cur->next = nullptr;
		cur->count = 0;

		graph[_node] = cur;
	}
	else
	{
		for (int i = 0; i < cnt; i++)
		{
			Node* cur = new Node[cnt - 1];
			int temp = 0;
			for (int j = 0; j < cnt; j++)
			{
				if (i == j)
				{
					temp++;

				}
				cur[j].data = graph[_node][0].data;
				cur[j].count = cnt - 1;
				cur[j].next = nullptr;
				cur[j].next = graph[cnt][j + temp].next;
			}
			graph[_node] = cur;
			break;
		}
	}


	return graph[_node];
}


Graph::Graph()
{
	graph = nullptr;

}

Graph::~Graph()
{
	for (int i = 0; i < 9; i++)
	{
		graph[i] = CreateNode(0);
		delete graph[i];
		graph[i] = nullptr;
	}
	delete[] graph;
}
