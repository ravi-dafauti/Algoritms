/*
Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Input:The first line contains an integer 'T' denoting the total number of test cases. Each test case constitutes of two lines. First line contains 'N', representing the number of elements in the set and the second line contains the elements of the set.
Output: Print YES if the given set can be partioned into two subsets such that the sum of elements in both subsets is equal, else print NO.
Constraints:

1 <= T<= 100
1 <= N<= 100
0 <= arr[i]<= 1000


Example:

Input:
2
4
1 5 11 5
3
1 3 5

Output:

YES
NO
*/

#include<iostream>
using namespace std;
int funUtil(int arr[], int n, int index, int sum)
{
	if (sum<0 || index >= n)
		return 0;
	if (sum == 0)
		return 1;
	if (arr[index] == sum)
		return 1;
	if (funUtil(arr, n, index + 1, sum))
		return 1;
	if (funUtil(arr, n, index + 1, sum - arr[index]))
		return 1;
	return 0;

}
int myfun(int arr[], int n, int s)
{
	int **dp = new int*[n + 1];
	for (int i = 0; i <= n; i++)
		dp[i] = new int[s + 1];
	for (int i = 0; i < n + 1; i++)
	{
		dp[i][0] = 1;
	}
	for (int i = 1; i <= s; i++)
		dp[0][i] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= s; j++)
		{
			if ((dp[i - 1][j]) || (j >= arr[i - 1] && dp[i - 1][j - arr[i - 1]]))
			{
				dp[i][j] = 1;
			}
			else
				dp[i][j] = 0;
		}
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= s; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	int ans = dp[n][s];
	return ans;

}
void fun(int arr[], int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		s += arr[i];
	}
	if (s % 2 != 0)
		cout << "NO";
	else
	{
		if (myfun(arr, n, s/2))
			cout << "YES";
		else
			cout << "NO";
	}
}
int main()
{
	int t;
	cin >> t;
	int n;
	int arr[105];
	while (t)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		fun(arr, n);
		cout << "\n";
		t--;
	}
	return 0;
}

