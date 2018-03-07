/*Given an array of n positive integers.
Write a program to find the sum of maximum sum subsequence of the given array such that the intgers in the subsequence are sorted in increasing order. 
For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100),
if the input array is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10) and if the input array is {10, 5, 4, 3}, then output should be 10*/

#include<iostream>
using namespace std;
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int maxSum(int arr[], int n)
{
	int *dp = new int[n];
	for (int i = 0; i < n; i++)
		dp[i] = arr[i];
	int max_sum = arr[0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i]>arr[j])
			{
				dp[i] = max(dp[i], dp[j] + arr[i]);
				if (dp[i]>max_sum)
					max_sum = dp[i];
			}
		}
	}
	return max_sum;
}
int main()
{
	int arr[] = { 1, 101, 2, 3, 100, 4, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum sum of increasing subsequence is : " << maxSum(arr, size);
	return 0;
}