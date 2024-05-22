#include "star.h"
#include <Windows.h>

using namespace std;

#pragma region Enum
enum Color
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE,
};
#pragma endregion

#pragma region WinAPI
void MoveCursorPosition(int x, int y);
void HideCursor();
void ChangeColor(int color);
#pragma endregion

void View(star st);

int main()
{
	star st;
	int startX = 2;
	int startY = 2;
	Node* sNode = st.arr[startY][startX];
	st.Start(sNode);
	int lastX = 27;
	int lastY = 25;

	Node* fNode = st.arr[lastY][lastX];
	st.End(fNode);

	int eX = 3;
	int eY = 17;
	Node* eNode = st.arr[eY][eX];
	st.eStart(eNode);


	HideCursor();

	for (int i = 5; i < 6; i++)
	{
		for (int j = 5; j < 13; j++)
		{
			Node* xNode = st.arr[i][j];
			st.Hole(xNode);
		}
	}
	
	for (int i = 15; i < 16; i++)
	{
		for (int j = 15; j < 23; j++)
		{
			Node* xNode = st.arr[i][j];
			st.Hole(xNode);
		}
	}


	while (true)
	{
		system("cls");
		
		
		sNode = st.FindDis(sNode, fNode);
		View(st);

		if (sNode->find == 4)break;
		Sleep(100);

	}
}

void View(star st)
{
	for (int i = 0; i < MaxY; i++)
	{
		for (int j = 0; j < MaxX; j++)
		{
			if (st.arr[i][j]->find == 1)
				cout << "¡Ú";
			else if (st.arr[i][j]->find == 99)
				cout << "¡á";
			else if (st.arr[i][j]->find == 2)
				cout << "¡Ù";
			else if (st.arr[i][j]->find == 3)
				cout << "¡Þ";
			else if (st.arr[i][j]->find == 4)
				cout << "¡ß";
			else if (st.arr[i][j]->find == 10)
				cout << "£À";

			else cout << "¡à";
		}
		cout << endl;
	}
}







#pragma region WinAPI
void MoveCursorPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void HideCursor()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 1;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void ChangeColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

#pragma endregion

