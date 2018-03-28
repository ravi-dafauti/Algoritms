/*
Given an array, the task is to find to LIS (Longest Increasing Subsequence) in a circular way.

Examples:

Input : arr[] = {5, 4, 3, 2, 1}
Output : 2
Although there is no LIS in a given array 
but in a circular form there can be
{1, 5}, {2, 5}, ...... 

Input : arr[]= {5, 6, 7, 1, 2, 3}
Output : 6
{1, 2, 3, 5, 6, 7} will be the LIS in the
circular manner.
*/

#include<iostream>
using namespace std;

#define MIN -999999
int globalmax = -999999;
int LICS(int arr[], int n)
{
	int *newarr = new int[2 * n];
	int i, j;
	for (i = 0,j=n; i < n; i++,j++)
	{
		newarr[i] = arr[i];
		newarr[j] = arr[i];
	}
	int k = n;
	for (int i = 0; (i + k -1) < 2 * n; i++)
	{
		int *dp = new int[n];
		for (j = 0; j < n; j++)
			dp[i] = MIN;
		dp[0] = 1;
		for (int l = i+1; l <= i + k - 1; l++)
		{

			for (int lj = i; lj < l; lj++)
			{
				if (newarr[l] > newarr[lj])
				{
					if (dp[l - i] < dp[lj - i] + 1)
					{
						dp[l - i] = dp[lj - i] + 1;
						if (dp[l - i] > globalmax)
						{
							globalmax = dp[l - i];
						}
					}
				}
			}
		}
	}
	return globalmax;
}
int main()
{
	int arr[] = { 5,6,7,1,2,3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Length of LICS is " << LICS(arr, n);
    return 0;
}

