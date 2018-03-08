/*
LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. So a string of length n has 2^n different possible subsequences.

It is a classic computer science problem, the basis of diff (a file comparison program that outputs the differences between two files), and has applications in bioinformatics.

Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

*/
#include<iostream>
#include<stack>
using namespace std;
int max(int a, int b, int c)
{
	int max;
	if (a > b)
		max = a;
	else
		max = b;
	if (max < c)
		max = c;
	return max;
}
void lcs(char X[], char Y[], int m, int n)
{
	int **table = (int **)malloc(sizeof(int)*(m + 1));
	for (int i = 0; i <= m; i++)
		table[i] = (int *)malloc(sizeof(int)*(n + 1));
	for (int i = 0; i <= m; i++)
		table[i][0] = 0;
	for (int i = 1; i <= n; i++)
		table[0][i] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (X[i - 1] == Y[j - 1])
			{
				table[i][j] = 1 + table[i - 1][j - 1];
			}
			else
			{
				table[i][j] = max(table[i - 1][j], table[i][j - 1], table[i - 1][j - 1]);
			}
		}
	}

	cout << "length of longest common subsequence is : " << table[m][n] << "\n";
	cout << "subsequence is : ";
	int i = m;
	int j = n;
	stack<char> s;
	while (i > 0 && j > 0)
	{
		if (X[i - 1] == Y[j - 1])
		{
			s.push(X[i - 1]);
			i = i - 1;
			j = j - 1;
		}
		else
		{
			if (table[i - 1][j] == table[i][j])
				i = i - 1;
			else if (table[i][j - 1] == table[i][j])
				j = j - 1;
			else
			{
				i = i - 1;
				j = j - 1;
			}
		}
	}
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}
int main()
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	int m = strlen(X);
	int n = strlen(Y);

	lcs(X, Y, m, n);

	return 0;
}