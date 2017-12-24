// Sudoku.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#define N 9

void findEmptyCell(int arr[N][N],int *row, int *col)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 0)
			{
				*row = i;
				*col = j;
				return;
			}
		}
	}
}

int isSafe(int arr[N][N], int row, int col, int digit)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		if (arr[row][i] == digit)
		{
			return 0;
		}
	}
	for (i = 0; i < N; i++)
	{
		if (arr[i][col] == digit)
		{
			return 0;
		}
	}
	int box_start_row = row - (row % 3);
	int box_start_col = col - (col % 3);
	for (i = box_start_row; i < box_start_row + 3; i++)
	{
		for (j = box_start_col; j < box_start_col + 3; j++)
		{
			if (arr[i][j] == digit)
			{
				return 0;
			}
		}
	}
	return 1;
}
bool Sudoku(int arr[N][N])
{
	int row = -1;
	int col = -1;
	findEmptyCell(arr, &row, &col);
	if (row == -1 && col == -1)
	{
		return true;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (isSafe(arr, row, col, i))
		{
			arr[row][col] = i;
			if (Sudoku(arr) == true)
			{
				return true;
			}
			arr[row][col] = 0;
		}
	}
	return false;
}

void printSol(int arr[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int chart[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
	{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
	{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
	{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
	{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
	{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
	{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
	if (Sudoku(chart) == true)
		printSol(chart);
	else
		printf("No solution\n");
    return 0;
}

