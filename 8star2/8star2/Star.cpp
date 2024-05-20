#include "Star.h"

void Star::Init(int x, int y)
{
	arr[y][x].x = x;
	arr[y][x].y = y;
	arr[y][x].find = 1;
	arr[y][x].parent = nullptr;

}

void Star::Hole(int x, int y)
{
	arr[y][x].find = 99;
}

void Star::FindDisT(int nX, int nY, int lX, int lY, Node cNode)
{
	if (nX < 0 || nY < 0) return;
	if (nX >= MaxX || nY >= MaxY) return;
	if (arr[nY][nX].find == 99 || arr[nY][nX].find != 0) return;
	arr[nY][nX].x = nX;
	arr[nY][nX].y = nY;
	arr[nY][nX].move = cNode.move + 10;
	int res = 0;
	int resX = lX >= nX ? lX - nX : nX - lX;
	int resY = lY >= nY ? lY - nY : nY - lY;
	if (resX >= resY)
	{
		res = resY * 14 + (resX - resY) * 10;
	}
	else res = resX * 14 + (resY - resX) * 10;
	arr[nY][nX].Mdis = res;
	arr[nY][nX].res = arr[nY][nX].move + arr[nY][nX].Mdis;


	arr[nY][nX].find = 2;
	arr[nY][nX].parent = &arr[cNode.y][cNode.x];


	lb.push_back(arr[nY][nX]);
}

void Star::FindDisX(int nX, int nY, int lX, int lY, Node cNode)
{
	if (nX < 0 || nY < 0) return;
	if (nX >= MaxX || nY >= MaxY) return;
	if (arr[nY][nX].find == 99 || arr[nY][nX].find != 0) return;
	arr[nY][nX].x = nX;
	arr[nY][nX].y = nY;
	arr[nY][nX].move = cNode.move + 14;
	int res = 0;
	int resX = lX >= nX ? lX - nX : nX - lX;
	int resY = lY >= nY ? lY - nY : nY - lY;
	if (resX >= resY)
	{
		res = resY * 14 + (resX - resY) * 10;
	}
	else res = resX * 14 + (resY - resX) * 10;
	arr[nY][nX].Mdis = res;
	arr[nY][nX].res = arr[nY][nX].move + arr[nY][nX].Mdis;


	arr[nY][nX].find = 2;
	arr[nY][nX].parent = &arr[cNode.y][cNode.x];


	lb.push_back(arr[nY][nX]);
}

Star::Star()
{
}

Star::~Star()
{
}
