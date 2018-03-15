/*
Given an n x n matrix and a number x, find position of x in the matrix if it is present in it. Else print “Not Found”. 
In the given matrix, every row and column is sorted in increasing order. The designed algorithm should have linear time complexity.

Example :

Input : mat[4][4] = { {10, 20, 30, 40},
{15, 25, 35, 45},
{27, 29, 37, 48},
{32, 33, 39, 50}};
x = 29
Output : Found at (2, 1)

Input : mat[4][4] = { {10, 20, 30, 40},
{15, 25, 35, 45},
{27, 29, 37, 48},
{32, 33, 39, 50}};
x = 100
Output : Element not found
*/
#include<iostream>
using namespace std;
void search(int mat[][4], int n, int data)
{
	int i, j;
	i = 0;
	j = n - 1;
	while (i <n&&j>=0)
	{
		if (data == mat[i][j])
		{
			cout << "pos is : (" << i << "," << j << ")";
			break;
		}
		else if (data < mat[i][j])
		{
			j--;
		}
		else if (data > mat[i][j])
		{
			i++;
		}
	}

}
int main()
{
	int mat[4][4] = { { 10, 20, 30, 40 },
	{ 15, 25, 35, 45 },
	{ 27, 29, 37, 48 },
	{ 32, 33, 39, 50 },
	};
	search(mat, 4, 29);
	return 0;
}