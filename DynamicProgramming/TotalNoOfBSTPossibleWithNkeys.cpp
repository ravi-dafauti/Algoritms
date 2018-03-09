/*
find the Total number of possible Binary Search Trees with n different keys
Total number of possible Binary Search Trees with n different keys = Catalan number Cn = (2n)!/(n+1)!*n!
*/
#include<iostream>
using namespace std;
int noOfBST(int n)
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
int noOFBSTRecur(int n)
{
	if (n == 0 || n == 1)
		return 1;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += noOFBSTRecur(i)*noOFBSTRecur(n - i - 1);
	}
	return sum;
}
int main()
{
	int n = 5;
	cout << "total no of BST possible with n = " << n << " is : " << noOFBSTRecur(n);
	return 0;
}