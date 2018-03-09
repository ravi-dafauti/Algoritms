/*
if the given sequence is “BBABCBCAB”, then the output should be 7 as “BABCBAB” is the longest palindromic subseuqnce in it.
“BBBBB” and “BBCBB” are also palindromic subsequences of the given sequence, but not the longest ones.*/
#include<iostream>
using namespace std;
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
void longestPalindromicSubsequence(char X[], int n)
{
	int **table = (int **)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		table[i] = (int *)malloc(sizeof(int)*n);
	int l;
	for (int i = 0; i < n; i++)
		table[i][i] = 1;
	for (int i = 0; i < n - 1; i++)
	{
		if (X[i] == X[i + 1])
			table[i][i + 1] = 2;
		else
			table[i][i + 1] = 1;
	}
	for (l = 3; l <= n; l++)
	{
		for (int i = 0; i + l - 1 < n; i++)
		{
			int j = i + l - 1;
			if (X[i] == X[j])
			{
				table[i][j] = table[i + 1][j - 1] + 2;
			}
			else
			{
				table[i][j] = max(table[i + 1][j], table[i][j - 1]);
			}
		}
	}
	cout << table[0][n - 1];
}
int main()
{
	char X[] = "GEEKS FOR GEEKS";
	int n = strlen(X);
	longestPalindromicSubsequence(X, n);
	return 0;
}