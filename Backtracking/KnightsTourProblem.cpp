// KnightsTourProblem.cpp : Defines the entry point for the console application.

#include<iostream>
#define N 8
using namespace std;

int chess[N][N];

void printSol()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << chess[i][j] << " ";
		}
		cout << "\n";
	}
}

int isSafe(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 &&
		y < N && chess[x][y] == -1);
}
int solveUtil(int movex[], int movey[], int x, int y, int moves)
{
	if (moves == N*N)
	{
		return 1;
	}
	for (int i = 0; i < N; i++)
	{
		int mx = x + movex[i];
		int my = y + movey[i];
		if (isSafe(mx, my))
		{
			chess[mx][my] = moves;
			if (solveUtil(movex, movey, mx, my, moves + 1)==1)
			{
				return 1;
			}
			else
			chess[mx][my] = -1;
		}
	}
	return 0;
}
void solveKTP()
{
	int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
	int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			chess[i][j] = -1;
		}
	}
	chess[0][0] = 0;
	if (solveUtil(xMove, yMove, 0, 0, 1)==1)
	{
		printSol();
	}
	else
	{
		cout << "solution doesn't exists";
	}
}
int main()
{
	solveKTP();
    return 0;
}

