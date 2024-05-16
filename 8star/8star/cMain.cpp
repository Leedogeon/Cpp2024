#include<iostream>
#include<map>
#include<queue>

using namespace std;
#define MaxX 10
#define MaxY 7

struct block
{
	int x;
	int y;
	int res;
};
void FindDisT(int nX, int nY, int lX, int lY);
void FindDisX(int nX, int nY, int lX, int lY);

int arr[3][MaxY][MaxX] = {};
int arr2[1][MaxY][MaxX] = {};
queue<block> qb;
int main()
{
	//arr[0][3][2] = 99;
	//arr[0][3][3] = 99;
	//arr[0][3][4] = 99;
	//arr[0][3][5] = 99;

	arr[0][1][1] = 1;
	arr[0][5][8] = -1;
	int startX = 1;
	int startY = 1;
	int nextX = startX;
	int nextY = startY;
	int lastX = 8;
	int lastY = 5;
	int disX = 0;
	int disY = 0;

	FindDisX(nextX-1, nextY-1, lastX, lastY);
	cout << arr[2][nextX-1][nextY-1];


	//while (nextX != lastX && nextY != lastY)
	//{
	//	cout << "X = " << nextX << endl;
	//	cout << "Y = " << nextY << endl;
	//	int temp = 1000;
	//	int nx=nextX;
	//	int ny=nextY;
	//	FindDisT(nextX + 1, nextY, lastX, lastY);
	//	FindDisX(nextX + 1, nextY + 1, lastX, lastY);
	//	FindDisT(nextX, nextY + 1, lastX, lastY);
	//	FindDisX(nextX - 1, nextY + 1, lastX, lastY);
	//	FindDisT(nextX - 1, nextY, lastX, lastY);
	//	FindDisX(nextX - 1, nextY - 1, lastX, lastY);
	//	FindDisT(nextX, nextY - 1, lastX, lastY);
	//	FindDisX(nextX + 1, nextY - 1, lastX, lastY);

	//	for (int i = 0; i < qb.size(); i++)
	//	{
	//		if (temp > qb.front().res)
	//		{
	//			temp = qb.front().res;
	//			nx = qb.front().x;
	//			ny = qb.front().y;
	//		}
	//		else if (temp == qb.front().res)
	//		{
	//			if (arr[1][nx][ny] > arr[1][qb.front().x][qb.front().y])
	//			{
	//				temp = qb.front().res;
	//				nx = qb.front().x;
	//				ny = qb.front().y;
	//			}
	//		}
	//		qb.pop();
	//	}

	//	nextX = nx;
	//	nextY = ny;

	//}
	


	return 0;
}

void FindDisT(int nX, int nY, int lX, int lY)
{
	if (nX < 0 || nY < 0) return;
	if (arr[0][nX][nY] == 99) return;

	arr[0][nX][nY] = 10;
	int res = 0;
	int resX = lX - nX;
	int resY = lY - nY;
	if (resX >= resY)
	{
		res = resY * 14 + (resY - resX) * 10;
	}
	else res = resX * 14 + (resX - resY) * 10;
	arr[1][nX][nY] = res;
	arr[2][nX][nY] = arr[0][nX][nY] + arr[1][nX][nY];
	
	qb.push({ arr[0][nX][nY], arr[1][nX][nY], arr[2][nX][nY] });



}
void FindDisX(int nX, int nY, int lX, int lY)
{
	if (nX < 0 || nY < 0) return;
	if (arr[0][nX][nY] == 99) return;
	arr[0][nX][nY] = 14;
	int res = 0;
	int resX = lX - nX;
	int resY = lY - nY;
	if (resX >= resY)
	{
		res = resY * 14 + (resY - resX) * 10;
	}
	else res = resX * 14 + (resX - resY) * 10;
	arr[1][nX][nY] = res;
	arr[2][nX][nY] = arr[0][nX][nY] + arr[1][nX][nY];

	qb.push({ arr[0][nX][nY], arr[1][nX][nY], arr[2][nX][nY] });

}