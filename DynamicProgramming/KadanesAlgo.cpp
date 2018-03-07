/*find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.*/
#include<iostream>
using namespace std;
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int kadanes(int arr[], int n)
{
	int *dp = new int[n];
	dp[0] = arr[0];
	int max_sum = arr[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		if (dp[i]>max_sum)
			max_sum = dp[i];
	}
	return max_sum;
}
int main()
{
	int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "maximum sum subarray sum is : " << kadanes(arr, size);
	return 0;
}