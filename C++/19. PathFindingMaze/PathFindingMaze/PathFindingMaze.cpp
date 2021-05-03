#include <Windows.h>
#include <iostream>
#include <stack>
#include <ctime>
using namespace std;

#define MAZESIZE_X 21
#define MAZESIZE_Y 21
#define EXIT_X 19
#define EXIT_Y 19

struct Position {
	int x;
	int y;
	int d;
};

struct Mtable {
	int x;
	int y;
};

int Maze[MAZESIZE_X][MAZESIZE_Y] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

Mtable Move[5] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0},
	{0, 0}
};

int Mark[MAZESIZE_X][MAZESIZE_Y];
int top;
Position Trace[(MAZESIZE_X - 2) * (MAZESIZE_Y - 2)];

int beforeX;
int beforeY;

void ShowMaze(Position);
void makeMazePrint(Position, int);
void moveMazePrint(Position);
void Push(Position);
void Pop(Position* p);

void gotoXY(int x, int y)
{
	HANDLE hOut;
	COORD Cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}

void setcursor(bool i, DWORD size)
{
	CONSOLE_CURSOR_INFO c = { 0 };
	c.dwSize = size;
	c.bVisible = i;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);
}

void makeRandomMaze()
{
	const int mazeMaxSizeX = (MAZESIZE_X - 1) / 2;
	const int mazeMaxSizeY = (MAZESIZE_Y - 1) / 2;
	int mazeCheck[mazeMaxSizeX][mazeMaxSizeY] = { 0, };

	stack<Position> mazeStack;
	Position currentPosition = { 0, 0, 0 };
	mazeStack.push(currentPosition);
	mazeCheck[currentPosition.x][currentPosition.y] = 1;
	int dir = 0;
	int dirCheck[4] = { 0, 0, 0, 0 };

	ShowMaze({ 1, 1 });
	gotoXY(0, MAZESIZE_Y + 2);
	cout << endl << "미로를 만드는 중";

	beforeX = 1;
	beforeY = 1;

	while (!mazeStack.empty())
	{
		while (true)
		{
			dir = rand() % 4;

			if (dirCheck[dir] == 0)
			{
				dirCheck[dir] = 1;
				int moveX = Move[dir].x;
				int moveY = Move[dir].y;

				if (currentPosition.x + moveX >= 0 && currentPosition.x + moveX < mazeMaxSizeX && currentPosition.y + moveY >= 0 && currentPosition.y + moveY < mazeMaxSizeY && mazeCheck[currentPosition.x + moveX][currentPosition.y + moveY] == 0)
				{
					Maze[currentPosition.x * 2 + 1][currentPosition.y * 2 + 1] = 0;
					Maze[(currentPosition.x * 2 + 1) + moveX * 2][(currentPosition.y * 2 + 1) + moveY * 2] = 0;
					Maze[(currentPosition.x * 2 + 1) + moveX][(currentPosition.y * 2 + 1) + moveY] = 0;
					makeMazePrint({ currentPosition.x * 2 + 1, currentPosition.y * 2 + 1 }, dir);
					currentPosition.x += moveX;
					currentPosition.y += moveY;
					mazeStack.push(currentPosition);
					mazeCheck[currentPosition.x][currentPosition.y] = 1;
					break;
				}
			}
			else
			{
				bool isDir = false;

				for (int i = 0; i < 4; i++)
				{
					if (dirCheck[i] == 0)
					{
						isDir = true;
						break;
					}
				}

				if (isDir == false)
				{
					currentPosition.x = mazeStack.top().x;
					currentPosition.y = mazeStack.top().y;
					mazeStack.pop();
					makeMazePrint({ currentPosition.x * 2 + 1, currentPosition.y * 2 + 1 }, 5);
					break;
				}
			}
		}

		for (int i = 0; i < 4; i++)
		{
			dirCheck[i] = 0;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	setcursor(false, 1);

	int isFound = FALSE;
	int dir;

	Position Now = { 1, 1, 0 };
	Position Next;

	makeRandomMaze();

	Push(Now);

	beforeX = Now.x;
	beforeY = Now.y;

	ShowMaze(Now);
	gotoXY(0, MAZESIZE_Y + 2);
	cout << endl << "미로에서 길을 찾는 중";

	while (!isFound && top > 0)
	{
		Pop(&Now);
		dir = Now.d;

		while (dir < 4)
		{
			Next.x = Now.x + Move[dir].x;
			Next.y = Now.y + Move[dir].y;

			if (Next.x == EXIT_X && Next.y == EXIT_Y)
			{
				Next.d = dir;
				Push(Next);
				isFound = TRUE;
				break;
			}
			else if ((Maze[Next.x][Next.y] == 0) && (Mark[Next.x][Next.y] == 0))
			{
				Now.d = ++dir;
				Push(Now);

				Now.x = Next.x;
				Now.y = Next.y;
				dir = 0;

				Mark[Next.x][Next.y] = 1;
			}
			else dir++;

			moveMazePrint(Now);
		}
	}

	if (isFound == TRUE)
	{
		beforeX = Trace[0].x;
		beforeY = Trace[0].y;

		ShowMaze(Trace[0]);

		gotoXY(0, MAZESIZE_Y + 2);
		cout << endl << "미로에서 정답을 보여주는 중";

		for (int i = 0; i < top; i++)
		{
			moveMazePrint(Trace[i]);
		}
	}
	else
	{
		gotoXY(0, MAZESIZE_Y + 4);
		cout << "Not Found!" << endl;

		system("pause");
		return 0;
	}

	gotoXY(0, MAZESIZE_Y + 4);
}

void ShowMaze(Position p)
{
	Sleep(100);
	system("cls");
	gotoXY(0, 0);

	cout << "출구는 (" << EXIT_X << ", " << EXIT_Y << ")" << endl;

	cout << "현재 좌표는 " << p.x << " " << p.y << " " << p.d << endl;

	for (int i = 0; i < MAZESIZE_X; i++)
	{
		for (int j = 0; j < MAZESIZE_Y; j++)
		{
			if (Maze[i][j] == 1) cout << "#";
			else if (p.x == i && p.y == j) cout << '&';
			else cout << " ";
		}

		cout << endl;
	}
}

void makeMazePrint(Position p, int dir)
{
	Sleep(100);

	gotoXY(0, 1);
	cout << "                      ";

	gotoXY(0, 1);
	cout << "현재 좌표는 " << p.x << " " << p.y << " " << p.d << endl;

	gotoXY(p.y + Move[dir].y, (p.x + Move[dir].x) + 2);
	cout << " ";

	gotoXY(p.y + Move[dir].y * 2, (p.x + Move[dir].x * 2) + 2);
	cout << " ";

	gotoXY(p.y, p.x + 2);
	cout << "&";

	gotoXY(beforeY, beforeX + 2);
	cout << " ";

	beforeX = p.x;
	beforeY = p.y;
}

void moveMazePrint(Position p)
{
	Sleep(100);

	gotoXY(0, 1);
	cout << "                      ";

	gotoXY(0, 1);
	cout << "현재 좌표는 " << p.x << " " << p.y << " " << p.d << endl;

	gotoXY(p.y, p.x + 2);
	cout << "&";

	gotoXY(beforeY, beforeX + 2);
	cout << " ";

	beforeX = p.x;
	beforeY = p.y;
}

void Push(Position P)
{
	Trace[top].x = P.x;
	Trace[top].y = P.y;
	Trace[top].d = P.d;
	top++;
}

void Pop(Position* P)
{
	top--;
	P->x = Trace[top].x;
	P->y = Trace[top].y;
	P->d = Trace[top].d;
}