#include "Star.h"

int main()
{
	Star st;
	int startX = 1;
	int startY = 1;
	int nextX = startX;
	int nextY = startY;
	int lastX = 8;
	int lastY = 5;
	int disX = 0;
	int disY = 0;

	st.arr[1][1].find = 1;

	while (nextX != lastX && nextY != lastY)
	{
		cout << "X = " << nextX << endl;
		cout << "Y = " << nextY << endl;
		st.FindDisT(nextX + 1, nextY, lastX, lastY);
		st.FindDisX(nextX + 1, nextY + 1, lastX, lastY);
		st.FindDisT(nextX, nextY + 1, lastX, lastY);
		st.FindDisX(nextX - 1, nextY + 1, lastX, lastY);
		st.FindDisT(nextX - 1, nextY, lastX, lastY);
		st.FindDisX(nextX - 1, nextY - 1, lastX, lastY);
		st.FindDisT(nextX, nextY - 1, lastX, lastY);
		st.FindDisX(nextX + 1, nextY - 1, lastX, lastY);

		list<Node>::iterator it = st.lb.begin();
		int temp = INT32_MAX;
		int nx = nextX;
		int ny = nextY;
		cout << "size = " << st.lb.size() << endl;
		for (int i = 0; i < st.lb.size(); i++)
		{
			cout << it->res << endl;
			if (st.arr[it->y][it->x].find == 1) continue;
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
	

}