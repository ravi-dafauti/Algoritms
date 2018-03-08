/*
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

Examples: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output:  True  //There is a subset (4, 5) with sum 9.

*/

#include<iostream>
using namespace std;
bool isSubsetSum(int set[], int n, int sum)
{
	bool **table = (bool**)malloc(sizeof(int)*(n + 1));
	for (int i = 0; i <= n; i++)
		table[i] = (bool*)malloc(sizeof(bool)*(sum + 1));
	for (int i = 0; i <= n; i++)
		table[i][0] = true;
	for (int i = 1; i <= sum; i++)
		table[0][i] = false;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			if (j < set[i - 1])
				table[i][j] = table[i - 1][j];
			else
			{
				table[i][j] = table[i - 1][j] ||table[i - 1][j - set[i - 1]];
			}
		}
	}
	return table[n][sum];
}
int main()
{
	int set[] = { 3, 34, 4, 12, 5, 2 };
	int sum = 9;
	int n = sizeof(set) / sizeof(set[0]);
	if (isSubsetSum(set, n, sum) == true)
		cout << "Found a subset with given sum";
	else
		cout << "No subset with given sum";
	return 0;
}