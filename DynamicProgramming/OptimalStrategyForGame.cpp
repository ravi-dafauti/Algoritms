/*
Consider a row of n coins of values v1 . . . vn, where n is even. We play a game against an opponent by alternating turns.
In each turn, a player selects either the first or last coin from the row, removes it from the row permanently,
and receives the value of the coin. Determine the maximum possible amount of money we can definitely win if we move first.

Note: The opponent is as clever as the user.
*/
#include<iostream>
using namespace std;
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int optimalStrategyOfGame(int arr[], int n)
{
	pair<int, int> **table = (pair<int,int> **)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		table[i] = (pair<int, int> *)malloc(sizeof(pair<int, int>)*n);
	for (int i = 0; i < n; i++)
	{
		table[i][i].first = arr[i];
		table[i][i].second = 0;
	}
	int l;
	for (l = 2; l <= n; l++)
	{
		for (int i = 0; i + l - 1 < n; i++)
		{
			int j = i + l - 1;
			if (arr[i] + table[i + 1][j].second > arr[j] + table[i][j - 1].second)
			{
				table[i][j].first = arr[i] + table[i + 1][j].second;
				table[i][j].second = table[i + 1][j].first;
			}
			else
			{
				table[i][j].first = arr[j] + table[i][j - 1].second;
				table[i][j].second = table[i][j - 1].first;
			}
		}
	}
	return table[0][n - 1].first;
}
int main()
{
	int arr1[] = { 8, 15, 3, 7 };
	int n = sizeof(arr1) / sizeof(arr1[0]);
	cout << optimalStrategyOfGame(arr1, n) << "\n";

	int arr2[] = { 2, 2, 2, 2 };
	n = sizeof(arr2) / sizeof(arr2[0]);
	cout << optimalStrategyOfGame(arr2, n) << "\n";

	int arr3[] = { 20, 30, 2, 2, 2, 10 };
	n = sizeof(arr3) / sizeof(arr3[0]);
	cout << optimalStrategyOfGame(arr3, n) << "\n";
	return 0;
}
