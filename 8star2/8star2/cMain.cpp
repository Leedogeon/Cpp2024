#include "Star.h";

int main()
{
	Star st;
	int startX = 1;
	int startY = 1;
	int nextX = startX;
	int nextY = startY;
	int lastX = 8;
	int lastY = 5;

	st.Init(startX, startY);
	
	for (int i = 2; i <= 6; i++)
	{
		st.Hole(i,3);
	}



	

	while (nextX != lastX || nextY != lastY)
	{
		Node cNode = st.arr[nextY][nextX];

		st.FindDisT(nextX + 1, nextY, lastX, lastY, cNode);
		st.FindDisX(nextX + 1, nextY + 1, lastX, lastY, cNode);
		st.FindDisT(nextX, nextY + 1, lastX, lastY, cNode);
		st.FindDisX(nextX - 1, nextY + 1, lastX, lastY, cNode);
		st.FindDisT(nextX - 1, nextY, lastX, lastY, cNode);
		st.FindDisX(nextX - 1, nextY - 1, lastX, lastY, cNode);
		st.FindDisT(nextX, nextY - 1, lastX, lastY, cNode);
		st.FindDisX(nextX + 1, nextY - 1, lastX, lastY, cNode);

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
	}


	Node cNode = st.arr[nextY][nextX];
	cout << "°æ·Î" <<  endl << cNode.x << " , " << cNode.y << endl;
	while (cNode.parent != nullptr)
	{
		cout << cNode.parent->x << " , " << cNode.parent->y << endl;
		cNode = *cNode.parent;
		
	}

}