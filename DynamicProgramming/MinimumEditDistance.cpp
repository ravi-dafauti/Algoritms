/*
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

Insert
Remove
Replace
All of the above operations are of equal cost.

Examples:

Input:   str1 = "geek", str2 = "gesek"
Output:  1
We can convert str1 into str2 by inserting a 's'.

Input:   str1 = "cat", str2 = "cut"
Output:  1
We can convert str1 into str2 by replacing 'a' with 'u'.

Input:   str1 = "sunday", str2 = "saturday"
Output:  3
Last three and first characters are same.  We basically
need to convert "un" to "atur".  This can be done using
below three operations.
Replace 'n' with 'r', insert t, insert a


If last characters of two strings are same, nothing much to do. Ignore last characters and get count for remaining strings. So we recur for lengths m-1 and n-1.
Else (If last characters are not same), we consider all operations on ‘str1’, consider all three operations on last character of first string, recursively compute minimum cost for all three operations and take minimum of three values.
Insert: Recur for m and n-1
Remove: Recur for m-1 and n
Replace: Recur for m-1 and n-1
*/
#include<iostream>
using namespace std;

int min(int a, int b, int c)
{
	int m;
	if (a < b)
		m = a;
	else
		m = b;
	if (m > c)
		m = c;
	return m;
}
int editDistDP(string str1, string str2, int n1, int n2)
{
	int **dp = (int **)malloc(sizeof(int)*(n2 + 1));
	for (int i = 0; i <= n2; i++)
		dp[i] = (int *)malloc(sizeof(int)*(n1 + 1));
	for (int i = 0; i <= n2; i++)
		dp[i][0] = i;
	for (int i = 0; i <= n1; i++)
		dp[0][i] = i;
	for (int i = 1; i <= n2; i++)
	{
		for (int j = 1; j <= n1; j++)
		{
			if (str2[i - 1] == str1[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[n2][n1];
}
int main()
{
	string str1 = "sunday";
	string str2 = "saturday";

	cout << editDistDP(str1, str2, str1.length(), str2.length());

	return 0;
}