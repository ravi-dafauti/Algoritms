/*
The cost of a stock on each day is given in an array, find the max profit that you can make by buying and selling in those days.
We are allowed to make only one transaction.
If the given array of prices is sorted in decreasing order, then profit cannot be earned at all.

the answer will be maximum difference between two numbers in array such that larger number occurs after smaller number
*/
#include<iostream>
using namespace std;
int max(int a, int b)
{
if (a > b)
return a;
return b;
}
//kadanes algo way
int maxProfit(int arr[], int size)
{
	int *diff = new int[size - 1];
	int *dp = new int[size - 1];
	//store the differences of adjacent elements
	for (int i = 1; i < size; i++)
	{
		diff[i - 1] = arr[i] - arr[i - 1];
	}
	// apply kadanes algo to find max sum submatrix
	for (int i = 0; i < size - 1; i++)
		dp[i] = diff[i];
	int max_profit = -9999999;
	for (int i = 1; i < size - 1; i++)
	{
		dp[i] = max(dp[i], dp[i - 1] + dp[i]);
		if (dp[i] > max_profit)
			max_profit = dp[i];
	}
	return max_profit;
}

int main()
{
	int arr[] = { 80, 2, 6, 3, 100 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum Profit is : " << maxProfit(arr, size);
	return 0;
}