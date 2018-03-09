/*
Given a string, find the longest substring which is palindrome.
For example, if the given string is “forgeeksskeegfor”, the output should be “geeksskeeg”.
*/
#include<iostream>
using namespace std;
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
void longestPalindromicSubstring(char X[], int n)
{
	int **table = (int **)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		table[i] = (int *)malloc(sizeof(int)*n);
	int l;
	int max_len = 1;
	int start, end;
	start = end = 0;
	for (int i = 0; i < n; i++)
		table[i][i] = 1;
	for (int i = 0; i < n - 1; i++)
	{
		if (X[i] == X[i + 1])
		{
			table[i][i + 1] = 2;
			if (max_len < 2)
			{
				start = i;
				end = i + 1;
				max_len = 2;
			}

		}
		else
			table[i][i + 1] = 1;
	}
	for (l = 3; l <= n; l++)
	{
		for (int i = 0; i + l - 1 < n; i++)
		{
			int j = i + l - 1;
			if (X[i] != X[j] || table[i + 1][j - 1] == 0)
				table[i][j] = 0;
			else
			{
				table[i][j] = table[i + 1][j - 1] + 2;
				if (table[i][j] > max_len)
				{
					start = i;
					end = j;
					max_len = table[i][j];
				}
			}
		}
	}
	cout << "maximum palindromic substring is : ";
	for (int i = start; i <= end; i++)
		cout << X[i];
}
int main()
{
	char X[] = "axbcbdaa";
	int n = strlen(X);
	longestPalindromicSubstring(X, n);
	return 0;
}