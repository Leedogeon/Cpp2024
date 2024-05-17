#include "Star.h"

void Star::FindDisT(int nX, int nY, int lX, int lY)
{
	if (nX < 0 || nY < 0) return;
	if (arr[nY][nX].find == 99 || arr[nY][nX].find == 1) return;
	arr[nY][nX].x = nX;
	arr[nY][nX].y = nY;
	arr[nY][nX].move += 10;
	int res = 0;
	int resX = lX - nX;
	int resY = lY - nY;
	if (resX >= resY)
	{
		res = resY * 14 + (resX - resY) * 10;
	}
	else res = resX * 14 + (resY - resX) * 10;
	arr[nY][nX].Mdis = res;
	arr[nY][nX].res = arr[nY][nX].move + arr[nY][nX].Mdis;

	lb.push_back(arr[nY][nX]);
}

void Star::FindDisX(int nX, int nY, int lX, int lY)
{
	if (nX < 0 || nY < 0) return;
	if (arr[nY][nX].find == 99 || arr[nY][nX].find == 1) return;
	arr[nY][nX].x = nX;
	arr[nY][nX].y = nY;
	arr[nY][nX].move += 14;
	int res = 0;
	int resX = lX - nX;
	int resY = lY - nY;
	if (resX >= resY)
	{
		res = resY * 14 + (resX - resY) * 10;
	}
	else res = resX * 14 + (resY - resX) * 10;
	arr[nY][nX].Mdis = res;
	arr[nY][nX].res = arr[nY][nX].move + arr[nY][nX].Mdis;

	lb.push_back(arr[nY][nX]);
}

Star::Star()
{
}

Star::~Star()
{
}
