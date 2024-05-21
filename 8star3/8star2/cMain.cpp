#include "Star.h"

int main()
{
	Star st;
	int startX = 2;
	int startY = 2;
	int nextX = startX;
	int nextY = startY;
	int lastX = 14;
	int lastY = 15;


	int eX = 0;
	int eY = 0;
	st.Init(startX, startY);
	
	for (int i = 3; i <= 7; i++)
	{
		st.Hole(i,6);
	}

	Node cNode = st.NewNode(nextY, nextX);
	Node fNode = st.NewNode(lastY, lastX);
	while (nextX != lastX || nextY != lastY)
	{
		
		
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				st.NewNode(nextY + i,nextX + j);
				Node nNode = st.arr[nextY+i][nextX+j];
				
				st.FindDisT(nNode, lastX,lastY, cNode);
			}
		}

		list<Node>::iterator it = st.lb.begin();
		int temp = INT32_MAX;
		int nx = nextX;
		int ny = nextY;
		for (int i = 0; i < st.lb.size(); i++)
		{
			if (st.arr[it->y][it->x].find == 1)
			{
				it++;
				continue;
			}
			if (temp > it->res)
			{
				temp = it->res;
				nx = it->x;
				ny = it->y;
			}
			else if (temp == it->res)
			{
				if (st.arr[ny][nx].Mdis > it->Mdis)
				{
					temp = it->res;
					nx = it->x;
					ny = it->y;
				}
			}
			it++;
		}
		nextX = nx;
		nextY = ny;
		st.arr[ny][nx].find = 1;

		cNode = st.arr[nextY][nextX];

	}


	Node cNode2 = st.arr[nextY][nextX];
	cout << "°æ·Î" <<  endl << cNode2.x << " , " << cNode2.y << endl;
	while (cNode2.parent != nullptr)
	{
		cout << cNode2.parent->x << " , " << cNode2.parent->y << endl;
		cNode2 = *cNode2.parent;
		
	}

	for (int i = MaxY-1; i >= 0; i--)
	{
		for (int j = 0; j < MaxX; j++)
		{
			if (st.arr[i][j].find == 1) cout << "¡Ú";
			else if (st.arr[i][j].find == 2) cout << "¡Ù";
			else if (st.arr[i][j].find == 99) cout << "¡á";
			else if (st.arr[i][j].find == 0) cout << "¡à";
		}
		cout << endl;
	}
}