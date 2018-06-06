/*
Given an N x N matrix, find a k x k submatrix where k <= N and k >= 1, such that sum of all the elements in submatrix is maximum. The input matrix can contain zero, positive and negative numbers.
*/
#include<iostream>
using namespace std;
#define N 5

void printMaxSumSub(int mat[N][N], int k)
{
	int **dp = new int*[N - k + 1];
	for (int i = 0; i < N - k + 1; i++)
		dp[i] = new int[N];
	for (int j = 0; j < N; j++)
	{
		int sum = 0;
		for (int i = 0; i < k; i++)
			sum += mat[i][j];
		dp[0][j] = sum;
		for (int i = 1; i < N - k + 1; i++)
		{
			dp[i][j] = dp[i - 1][j] - mat[i - 1][j] + mat[i + k - 1][j];
		}
	}

	int max = INT_MIN;
	int posi;
	int posj;
	for (int i = 0; i < N - k + 1; i++)
	{
		int curr_sum = 0;
		for (int j = 0; j < k; j++)
		{
			curr_sum += dp[i][k];
		}
		if (curr_sum > max)
		{
			max = curr_sum;
			posi = i;
			posj = 0;
		}
		for (int j = 1; j < N - k + 1; j++)
		{
			curr_sum = curr_sum - dp[i][j - 1] + dp[i][j + k - 1];
			if (curr_sum > max)
			{
				max = curr_sum;
				posi = i;
				posj = j;
			}
		}
	}

	for (int i = posi; i <= posi + k - 1; i++)
	{
		for (int j = posj; j <= posj + k - 1; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	int mat[N][N] = { { 1, 1, 1, 1, 1 },
	{ 2, 2, 2, 2, 2 },
	{ 3, 8, 6, 7, 3 },
	{ 4, 4, 4, 4, 4 },
	{ 5, 5, 5, 5, 5 },
	};
	int k = 3;

	cout << "Maximum sum 3 x 3 matrix is\n";
	printMaxSumSub(mat, k);
	return 0;
}

