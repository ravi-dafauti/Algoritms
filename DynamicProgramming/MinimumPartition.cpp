/*Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

If there is a set S with n elements, then if we assume Subset1 has m elements,
Subset2 must have n - m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum

*/
#include<iostream>
using namespace std;

#define MAX 99999
// solution is extension of subset sum problem
int findMin(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	int **dp = (int **)malloc(sizeof(int)*(n + 1));
	for (int i = 0; i <= n; i++)
	{
		dp[i] = (int *)malloc(sizeof(int)*((sum / 2) + 1));
	}
	for (int i = 0; i < ((sum / 2) + 1); i++)
		dp[0][i] = 0;
	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= (sum / 2); j++)
		{
			if (dp[i - 1][j] == 1)
				dp[i][j] = 1;
			else
			{
				if (arr[i - 1] <= j &&dp[i][j - arr[i - 1]] == 1)
					dp[i][j] = 1;
				else
					dp[i][j] = 0;
			}
		}
	}
	int i;
	int min_diff = MAX;
	for (i = sum / 2; i >= 0; i--)
	{
		if (dp[n][i] == 1)
		{
			min_diff = sum - 2 * i;
			break;
		}
	}
	return min_diff;
}
int main()
{
	int arr[] = { 3, 1, 4, 2, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The minimum difference between 2 sets is : " << findMin(arr, n);
	return 0;
}