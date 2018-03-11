/*
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.

We have many options to multiply a chain of matrices because matrix multiplication is associative. In other words, no matter how we parenthesize the product, the result will be the same. For example, if we had four matrices A, B, C, and D, we would have:

(ABC)D = (AB)(CD) = A(BCD) = ....
However, the order in which we parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency. For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then,

(AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.
Clearly the first parenthesization requires less number of operations.

Given an array p[] which represents the chain of matrices such that the ith matrix Ai is of dimension p[i-1] x p[i].
We need to write a function MatrixChainOrder() that should return the minimum number of multiplications needed to multiply the chain.

*/

#include<iostream>
using namespace std;
int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}
int MatrixChainOrder(int arr[], int size)
{
	int **table = (int **)malloc(sizeof(int)*(size - 1));
	for (int i = 0; i < size - 1; i++)
	{
		table[i] = (int *)malloc(sizeof(int)*(size - 1));
	}
	for (int i = 0; i < size - 1; i++)
		table[i][i] = 0;
	int l;
	for (l = 2; l <= size - 1; l++)
	{
		for (int i = 0; i + l - 1 < size - 1; i++)
		{
			int j = i + l - 1;
			if (l == 2)
			{
				table[i][j] = arr[i] * arr[j] * arr[j + 1];
			}
			else
			{
				table[i][j] = 99999;
				for (int k = i; k < j; k++)
				{
					if (table[i][k] + table[k + 1][j] + arr[i]*arr[k+1]*arr[j+1] < table[i][j])
					{
						table[i][j] = table[i][k] + table[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1];
					}
				}
			}
		}
	}
	return table[0][size - 2];
}
int main()
{
	int arr[] = { 1, 2, 3, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Minimum number of multiplications is : " << MatrixChainOrder(arr, size);

	return 0;
}