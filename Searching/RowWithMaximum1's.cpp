/*
Given a boolean 2D array, where each row is sorted.Find the row with the maximum number of 1s.

Example
Input matrix
0 1 1 1
0 0 1 1
1 1 1 1  // this row has maximum 1s
0 0 0 0

Output: 2
*/
#include<iostream>
using namespace std;
#define R 4
#define C 4

int maxRow(int mat[R][C])
{
	int i, j;
	int maxrow = 0;
	for (i = 0, j = C - 1; i < R && j >= 0;)
	{
		if (mat[i][j] == 1)
		{
			j--;
			maxrow = i;
		}
		else if (mat[i][j] == 0)
		{
			i++;
		}
	}
	return maxrow;
}
int main()
{
	int mat[R][C] = { { 0, 0, 0, 1 },
	{ 0, 1, 1, 1 },
	{ 1, 1, 1, 1 },
	{ 0, 0, 0, 0 } };

	cout << "row with maximum 1's : " << maxRow(mat);
	return 0;
}