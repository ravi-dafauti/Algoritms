// NQueenProblem.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<malloc.h>


void printSol(int **board, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}

int isSafe(int **board, int column, int row, int n)
{
	int i, j;
	for (i = row-1, j= column-1; i >=0&&j>=0; i--,j--)
	{
		if (board[i][j] == 1)
		{
			return 0;
		}
	}

	for (i = row + 1, j = column - 1; i < n && j >= 0; i++, j--)
	{
		if (board[i][j] == 1)
		{
			return 0;
		}
	}

	for (i = column - 1; i >= 0; i--)
	{
		if (board[row][i] == 1)
		{
			return 0;
		}
	}

	return 1;
}
int isPlacementPossible(int **board, int column, int n)
{
	if (column == n)
	{
		return 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (isSafe(board, column, i, n))
		{
			board[i][column] = 1;
			if (isPlacementPossible(board, column + 1, n))
			{
				return 1;
			}
			board[i][column] = 0;
		}
	}
	return 0;
}
void NQueenProb(int n)
{
	int **board;
	board = (int **)malloc(sizeof(int));
	for (int i = 0; i < n; i++)
	{
		board[i] = (int*)malloc(sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board[i][j] = 0;
		}
	}
	if (isPlacementPossible(board, 0, n))
	{
		printSol(board, n);
	}
	else
	{
		printf("solution dosent exists\n");
	}
}
int main()
{
	int N;
	int ans;
	printf("enter value of N\n");
	scanf("%d", &N);
	NQueenProb(N);
    return 0;
}

