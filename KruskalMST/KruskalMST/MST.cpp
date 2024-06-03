#include "MST.h"

void MST::Init(int nodeCount)
{
	graph = new Node * [nodeCount];
	vertexs = new bool[nodeCount];
	for (int i = 0; i < nodeCount; i++)
	{
		graph[i] = createNode(i);
		vertexs[i] = false;
	}
	for (int i = 0; i < (Max / 2); i++)
	{
		gr[i] = new Group({});
	}

}

void MST::AddEdge(int from, int to, int pio)
{
	if (graph[from][0].cnt == 0)
	{
		graph[from]->cnt++;

		if (graph[to][0].cnt == 0)
		{
			graph[to]->next = graph[from];
			graph[to]->pio = pio;
			graph[to]->cnt++;
		}
		else
		{
			Node* tNode = new Node[graph[to][0].cnt + 1];
			for (int i = 0; i < graph[to][0].cnt; i++)
			{
				tNode[i] = graph[to][i];
				tNode[i].data = graph[to][0].data;
				tNode[i].pio = graph[to][i].pio;
				tNode[i].cnt = graph[to][0].cnt + 1;
			}

			change(to, tNode);
			graph[to][(graph[to][0].cnt) - 1].next = graph[from];
			graph[to][(graph[to][0].cnt) - 1].pio = pio;
		}
		graph[from]->next = graph[to];
		graph[from]->pio = pio;
	}
	else
	{
		for (int i = 0; i < graph[from][0].cnt; i++)
		{
			if (graph[from][i].next == graph[to]) return;
		}


		for (int i = 0; i < graph[from][0].cnt; i++)
		{
			if (graph[from][i].next == graph[to])
				return;
		}

		Node* fNode = new Node[graph[from][0].cnt + 1];
		for (int i = 0; i < graph[from][0].cnt; i++)
		{
			fNode[i] = graph[from][i];
			fNode[i].pio = graph[from][i].pio;
			fNode[i].data = graph[from][0].data;
			fNode[i].cnt = graph[from][0].cnt + 1;
		}


		if (graph[to][0].cnt == 0)
		{
			graph[to]->cnt++;

			change(from, fNode);
			graph[from][graph[from][0].cnt - 1].next = graph[to];
			graph[from][graph[from][0].cnt - 1].pio = pio;
			graph[to]->next = graph[from];
			graph[to]->pio = pio;
			return;

		}
		else
		{
			Node* ttNode = new Node[graph[to][0].cnt + 1];
			for (int i = 0; i < graph[to][0].cnt; i++)
			{
				ttNode[i] = graph[to][i];
				ttNode[i].pio = graph[to][i].pio;
				ttNode[i].data = graph[to][0].data;
				ttNode[i].cnt = graph[to][0].cnt + 1;
			}

			change(from, fNode);
			change(to, ttNode);
			graph[from][graph[from][0].cnt - 1].next = graph[to];
			graph[from][graph[from][0].cnt - 1].pio = pio;

			graph[to][graph[to][0].cnt - 1].next = graph[from];
			graph[to][graph[to][0].cnt - 1].pio = pio;
		}

	}
	return;
}
void MST::ShowGraphEdge(int node)
{
	cout << graph[node]->data << " ";
	for (int i = 0; i < graph[node][0].cnt; i++)
	{
		cout << graph[node][i].next->data << " ";
	}
	cout << endl;

}

bool MST::visitVertex(int node)
{
	if (vertexs[node] == false) return vertexs[node] = true;
	else return vertexs[node] == false;
}

void MST::BreadthFirstSerch()
{
	queue<int> pque;

	for (int i = 1; i < Max; i++)
	{

		for (int j = 0; j < graph[i][0].cnt; j++)
		{
			int check = 0;
			for (auto num : FT)
			{
				if (num.from == i && num.to == graph[i][j].next->data)
				{
					check++;
					break;
				}
				if (num.from == graph[i][j].next->data && num.to == i)
				{
					check++;
					break;
				}
			}
			if (check == 0)
				FT.push_back({ i, graph[i][j].next->data, graph[i][j].pio });
		}
	}


	for (auto num : FT)
	{
		cout << "from = " << num.from << ", to = " << num.to << " , pio = " << num.pio << endl;
	}

	list<FromTo>::iterator iter = FT.begin();

	for (auto num : FT)
	{
		pFT.push({ iter->from,iter->to,iter->pio });
		iter++;
	}

	int pSz = pFT.size();
	for (int i = 0; i < pSz; i++)
	{
		for (int j = 0; j < (Max / 2); j++)
		{
			if (gr[j]->data.empty())
			{
				gr[j]->data.push_back(pFT.top().from);
				gr[j]->data.push_back(pFT.top().to);
				pFT.pop();
				break;
			}


			int ckF = 0;
			int ckT = 0;
			for (auto num : gr[j]->data)
			{
				if (num == pFT.top().from) ckF++;
				if (num == pFT.top().to) ckT++;
			}

			if (ckF == 0 && ckT == 0)
			{
				gr[j]->data.push_back(pFT.top().from);
				gr[j]->data.push_back(pFT.top().to);
			}
			else if (ckF == 0 && ckT != 0)
			{
				int Xck = 0;
				for (int i = 0; i < graph[pFT.top().from][0].cnt; i++)
				{
					for (auto num : gr[j]->data)
					{
						if (graph[pFT.top().from][i].next->data == num) Xck++;
					}
					if (Xck < 2)
					{
						gr[j]->data.push_back(pFT.top().from);
					}
					else continue;
				}
			}
			else if (ckT == 0)
			{
				int Xck = 0;
				for (int i = 0; i < graph[pFT.top().to][0].cnt; i++)
				{
					for (auto num : gr[j]->data)
					{
						if (graph[pFT.top().to][i].next->data == num) Xck++;
					}
					if (Xck < 2)
					{
						gr[j]->data.push_back(pFT.top().to);
					}
					else continue;
				}
			}

			pFT.pop();


		}


	}

	//int pft = pFT.size();
	//for (int i = 0; i < pft; i++)
	//{
	//    cout << pFT.top().pio << endl;
	//    pFT.pop();
	//}
}

Node* MST::createNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->next = nullptr;
	node->cnt = 0;
	node->pio = 0;

	return node;
}

void MST::change(int _base, Node* _cng)
{
	for (int i = 0; i < Max; i++)
	{
		if (graph[i][0].cnt != 0)
		{
			for (int j = 0; j < graph[i][0].cnt; j++)
			{
				if (graph[i][j].next == graph[_base])
				{
					graph[i][j].next = _cng;
					break;
				}
			}
		}
	}
	graph[_base] = _cng;
}



MST::MST()
{
	count = 0;
	vertexs = nullptr;
	graph = nullptr;
	
	for (int i = 0; i < Max; i++)
	{
		dis.insert({ i,0 });
		vs.insert({ i,0 });
	}
	for (int i = 0; i < (Max / 2) - 1; i++)
	{
		gr[i] = nullptr;
	}
}

MST::~MST()
{
}
