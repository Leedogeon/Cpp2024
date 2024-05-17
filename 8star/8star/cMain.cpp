#include<iostream>
#include<map>
#include<list>

using namespace std;
#define MaxX 10
#define MaxY 7

struct block
{
	int x;
	int y;
	int find;
	int Mdis;
	int move;
	int res;
};


void FindDisT(int nX, int nY, int lX, int lY);
void FindDisX(int nX, int nY, int lX, int lY);

block arr[MaxY][MaxX] = {};
list<block> lb;
int main()
{
	for (int i = 0; i < MaxY; i++)
	{
		for (int j = 0; j < MaxX; j++)
		{
			arr[i][j].x = j;
			arr[i][j].y = i;
		}
	}
	arr[3][2].find = 99;
	arr[3][3].find = 99;
	arr[3][4].find = 99;
	arr[3][5].find = 99;

	int startX = 1;
	int startY = 1;
	int nextX = startX;
	int nextY = startY;
	int lastX = 8;
	int lastY = 5;
	int disX = 0;
	int disY = 0;

	FindDisT(nextX + 1, nextY, lastX, lastY);
	FindDisX(nextX + 1, nextY + 1, lastX, lastY);
	FindDisT(nextX, nextY + 1, lastX, lastY);
	FindDisX(nextX - 1, nextY + 1, lastX, lastY);
	FindDisT(nextX - 1, nextY, lastX, lastY);
	FindDisX(nextX - 1, nextY - 1, lastX, lastY);
	FindDisT(nextX, nextY - 1, lastX, lastY);
	FindDisX(nextX + 1, nextY - 1, lastX, lastY);

	
	



	while (nextX != lastX && nextY != lastY)
	{
		cout << "X = " << nextX << endl;
		cout << "Y = " << nextY << endl;
		int temp = 1000;
		int nx=nextX;
		int ny=nextY;
		FindDisT(nextX + 1, nextY, lastX, lastY);
		FindDisX(nextX + 1, nextY + 1, lastX, lastY);
		FindDisT(nextX, nextY + 1, lastX, lastY);
		FindDisX(nextX - 1, nextY + 1, lastX, lastY);
		FindDisT(nextX - 1, nextY, lastX, lastY);
		FindDisX(nextX - 1, nextY - 1, lastX, lastY);
		FindDisT(nextX, nextY - 1, lastX, lastY);
		FindDisX(nextX + 1, nextY - 1, lastX, lastY);

		

		list<block>::iterator it = lb.begin();

		for (int i = 0; i < lb.size(); i++)
		{
			if (temp > it->res)
			{
				temp = it->res;
				nx = it->x;
				ny = it->y;
			}
			else if (temp == it->res)
			{
				if (arr[nx][ny].Mdis > arr[it->x][it->y].Mdis)
				{
					temp = it->res;
					nx = it->x;
					ny = it->y;
				}
			}
		}

		nextX = nx;
		nextY = ny;

	}
	


	return 0;
}

void FindDisT(int nX, int nY, int lX, int lY)
{
	if (nX < 0 || nY < 0) return;
	if (arr[nX][nY].find == 99) return;

	arr[nX][nY].move = 10;
	int res = 0;
	int resX = lX - nX;
	int resY = lY - nY;
	if (resX >= resY)
	{
		res = resY * 14 + (resX - resY) * 10;
	}
	else res = resX * 14 + (resY - resX) * 10;
	arr[nX][nY].Mdis = res;
	arr[nX][nY].res = arr[nX][nY].move + arr[nX][nY].Mdis;
	
	lb.push_back(arr[nX][nY]);

}
void FindDisX(int nX, int nY, int lX, int lY)
{
	if (nX < 0 || nY < 0) return;
	if (arr[nX][nY].find == 99) return;

	arr[nX][nY].move = 14;
	int res = 0;
	int resX = lX - nX;
	int resY = lY - nY;
	if (resX >= resY)
	{
		res = resY * 14 + (resX - resY) * 10;
	}
	else res = resX * 14 + (resY - resX) * 10;
	arr[nX][nY].Mdis = res;
	arr[nX][nY].res = arr[nX][nY].move + arr[nX][nY].Mdis;

	lb.push_back(arr[nX][nY]);

}