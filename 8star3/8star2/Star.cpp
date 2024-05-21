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
Node Star::NewNode(int y, int x)
{
	Node nNode = arr[y][x];
	arr[y][x].x = x;
	arr[y][x].y = y;
	return nNode;
}

void Star::FindDisT(Node nNode, int lX, int lY, Node cNode)
{
	if (nNode.x < 0 || nNode.y < 0) return;
	if (nNode.x >= MaxX || nNode.y >= MaxY) return;
	if (arr[nNode.y][nNode.x].find == 99 || arr[nNode.y][nNode.x].find != 0) return;

	if (abs(nNode.x - lX) == 1 && abs(nNode.y - lY) == 1)
		arr[nNode.y][nNode.x].move = cNode.move + 14;
	else arr[nNode.y][nNode.x].move = cNode.move + 10;

	int res = 0;
	int resX = lX >= nNode.x ? lX - nNode.x : nNode.x - lX;
	int resY = lY >= nNode.y ? lY - nNode.y : nNode.y - lY;
	if (resX >= resY)
	{
		res = resY * 14 + (resX - resY) * 10;
	}
	else res = resX * 14 + (resY - resX) * 10;
	arr[nNode.y][nNode.x].Mdis = res;
	arr[nNode.y][nNode.x].res = arr[nNode.y][nNode.x].move + arr[nNode.y][nNode.x].Mdis;


	arr[nNode.y][nNode.x].find = 2;
	arr[nNode.y][nNode.x].parent = &arr[cNode.y][cNode.x];


	lb.push_back(arr[nNode.y][nNode.x]);
}



Star::Star()
{
}

Star::~Star()
{
}
