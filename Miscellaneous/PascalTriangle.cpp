/*
Given an integer K,return the kth row of pascal triangle.
Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.

Example of pascal triangle:
1
1 1
1 2 1
1 3 3 1

for K=3, return 3rd row i.e 1 2 1


Input:

The first line contains an integer T,depicting total number of test cases.
Then following T lines contains an integer N depicting the row of triangle to be printed.


Output:

Print the Nth row of triangle in a separate line.


Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 25


Example:

Input
1
4
Output
1 3 3 1
*/

#include<iostream>
using namespace std;

void print(int n)
{
	int **arr = (int **)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		arr[i] = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			arr[i][j] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				arr[i][j] = 1;
			else
			{
				if (i == 0)
					break;
				else
				{
					arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << arr[n - 1][i] << " ";
}
int main()
{
	int t;
	cin >> t;
	while (t)
	{
		int n;
		cin >> n;
		print(n);
		cout << "\n";
		t--;
	}
    return 0;
}

