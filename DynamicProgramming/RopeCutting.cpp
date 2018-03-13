/*
Given a rope of length n meters, cut the rope in different parts of integer lengths in a way that maximizes product of lengths of all parts.
You must make at least one cut. Assume that the length of rope is more than 2 meters.

Examples:

Input: n = 2
Output: 1 (Maximum obtainable product is 1*1)

Input: n = 3
Output: 2 (Maximum obtainable product is 1*2)

Input: n = 4
Output: 4 (Maximum obtainable product is 2*2)

Input: n = 5
Output: 6 (Maximum obtainable product is 2*3)

Input: n = 10
Output: 36 (Maximum obtainable product is 3*3*4)
*/
#include<iostream>
using namespace std;
int maxProd(int l)
{
	int max = 0;
	int *dp = new int[l + 1];
	dp[0] = dp[1] = 0;
	for (int i = 2; i <= l; i++)
		dp[i] = 1;
	for (int i = 2; i <= l; i++)
	{
		for (int j = i + 1; j <= l; j++)
		{
			if (j - i <= i && i *(j - i)>dp[j])
				dp[j] = i *(j - i);
			if (j - i > i &&dp[j - i] * i > dp[j])
				dp[j] = dp[j - i] * i;
		}
	}
	return dp[l];
}
int main()
{
	cout << "Maximum Product is " << maxProd(10);
	return 0;
}