#include "Star.h"

void Star::FindDisT(int nX, int nY, int lX, int lY)
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

void Star::FindDisX(int nX, int nY, int lX, int lY)
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

Star::Star()
{
}

Star::~Star()
{
}
