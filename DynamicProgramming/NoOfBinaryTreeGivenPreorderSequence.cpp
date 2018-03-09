/*
Count the number of Binary Tree possible for a given Preorder Sequence length n.

Input : n = 1
Output : 1

Input : n = 2
Output : 2

Input : n = 3
Output : 5

this is same as CATALAN No
*/
#include<iostream>
using namespace std;
int noOfBT(int n)
{
	int *dp = new int[n + 1];
	for (int i = 0; i <= n; i++)
		dp[i] = 0;
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dp[i] += (dp[j] * dp[i - j - 1]);
		}
	}
	return dp[n];
}
int noOfBTRecurr(int n)
{
	if (n == 0 || n == 1)
		return 1;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += noOfBTRecurr(i)*noOfBTRecurr(n - i - 1);
	}
	return sum;
}
int main()
{
	int n = 5;
	cout << "total no of BT possible with n = " << n << " is : " << noOfBTRecurr(n);
	return 0;
}