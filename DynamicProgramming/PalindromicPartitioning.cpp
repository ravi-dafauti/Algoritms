/*
Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. 
For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. 
Determine the fewest cuts needed for palindrome partitioning of a given string. For example, minimum 3 cuts are needed for “ababbbabbababa”. 
The three cuts are “a|babbbab|b|ababa”. If a string is palindrome, then minimum 0 cuts are needed. 
If a string of length n containing all different characters, then minimum n-1 cuts are needed.
*/
#include<iostream>
using namespace std;
#define MAX 999999
int palindromicPartitioning(char str[], int n)
{
	int **table = (int **)malloc(sizeof(int)*n); // table[i][j] == 1 if substring from i to j is palindrome else 0
	for (int i = 0; i < n; i++)
		table[i] = (int *)malloc(sizeof(int)*n);
	int *C = new int[n];
	C[0] = 0;
	for (int i = 0; i < n; i++)
		table[i][i] = 1;
	for (int i = 0; i < n - 1; i++)
	{
		if (str[i] == str[i + 1])
			table[i][i + 1] = 1;
		else
			table[i][i + 1] = 0;
	}
	int l;
	for (l = 3; l <= n; l++)
	{
		for (int i = 0; i + l - 1 < n; i++)
		{
			int j = i + l - 1;
			if (str[i] == str[j] && table[i + 1][j - 1] == 1)
				table[i][j] = 1;
			else
				table[i][j] = 0;
		}
	}
	// after filling table check for minimum cuts
	//C[i]= minimum cut required for substring from 0 to i
	for (int i = 1; i < n; i++)
	{
		if (table[0][i] == 1)
			C[i] = 0;
		else
		{
			C[i] = MAX;
			for (int j = 0; j < i; j++)
			{
				if (table[j + 1][i] == 1 && C[i] > 1 + C[j])
					C[i] = 1 + C[j];
			}
		}
	}
	return C[n - 1];
}
int main()
{
	char str[] = "ababbbabbababa";
	int n = strlen(str);
	cout << "minimum no of cuts required are : " << palindromicPartitioning(str, n);
	return 0;
}