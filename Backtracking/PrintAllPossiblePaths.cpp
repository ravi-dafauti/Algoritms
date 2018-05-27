/*
The problem is to print all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down.

Examples :

Input : 1 2 3
4 5 6
Output : 1 4 5 6
1 2 5 6
1 2 3 6

Input : 1 2
3 4
Output : 1 2 4
1 3 4
*/
#include<iostream>
using namespace std;

/* mat:  Pointer to the starting of mXn matrix
i, j: Current position of the robot (For the first call use 0,0)
m, n: Dimentions of given the matrix
pi:   Next index to be filed in path array
*path[0..pi-1]: The path traversed by robot till now (Array to hold the
path need to have space for at least m+n elements) */

void printAllPathsUtil(int mat[][3], int i, int j, int m, int n, int *arr, int &index)
{
	if (i < 0 || i >= m || j < 0 || j >= n)
		return;
	arr[index++] = mat[i][j];
	if (i == m - 1 && j == n - 1)
	{
		for (int k = 0; k < index; k++)
			cout << arr[k] << " ";
		cout << "\n";
		index--;
		return;
	}
	printAllPathsUtil(mat, i + 1, j, m, n, arr, index);
	printAllPathsUtil(mat, i, j + 1, m, n, arr, index);
	index--;
}
void printAllPaths(int mat[][3], int m, int n)
{
	int *path = new int[m + n];
	int index = 0;
	printAllPathsUtil(mat, 0, 0, m, n, path, index);
}

// Driver program to test abve functions
int main()
{
	int mat[2][3] = { { 1, 2, 3 },{ 4, 5, 6 } };
	printAllPaths(mat, 2, 3);
	return 0;
}