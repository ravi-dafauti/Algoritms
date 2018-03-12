/*
Given a boolean expression with following symbols.

Symbols
'T' ---> true
'F' ---> false
And following operators filled between symbols

Operators
&   ---> boolean AND
|   ---> boolean OR
^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Let the input be in form of two arrays one contains the symbols (T and F) in order and other contains operators (&, | and ^}

Examples:

Input: symbol[]    = {T, F, T}
operator[]  = {^, &}
Output: 2
The given expression is "T ^ F & T", it evaluates true
in two ways "((T ^ F) & T)" and "(T ^ (F & T))"
*/
#include<iostream>
using namespace std;
int countParenth(char symbols[], char operators[], int n)
{
	int **T = (int **)malloc(sizeof(int)*n);
	int **F = (int **)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		T[i] = (int *)malloc(sizeof(int)*n);
		F[i] = (int *)malloc(sizeof(int)*n);
	}
	for (int i = 0; i < n; i++)
	{
		if (symbols[i] == 'T')
		{
			T[i][i] = 1;
			F[i][i] = 0;
		}
		else
		{
			T[i][i] = 0;
			F[i][i] = 1;
		}
	}
	int l;
	for (l = 2; l <= n; l++)
	{
		for (int i = 0; i + l - 1 < n; i++)
		{
			int j = i + l - 1;
			int t_left, t_right;
			T[i][j] = 0;
			F[i][j] = 0;
			for (int k = i; k < j; k++)
			{
				t_left = T[i][k] + F[i][k];
				t_right = T[k + 1][j] + F[k + 1][j];
				if (operators[k] == '&')
				{
					T[i][j] += (T[i][k] * T[k + 1][j]);
					F[i][j] += ((t_left*t_right) - (T[i][k] * T[k + 1][j]));
				}
				else if (operators[k] == '|')
				{
					T[i][j] += ((t_left*t_right) - (F[i][k] * F[k + 1][j]));
					F[i][j] += F[i][k] * F[k + 1][j];
				}
				else if (operators[k] == '^')
				{
					T[i][j] += ((T[i][k] * F[k + 1][j]) + (F[i][k] * T[k + 1][j]));
					F[i][j] += ((T[i][k] * T[k + 1][j]) + (F[i][k] * F[k + 1][j]));
				}
			}
		}
	}
	return T[0][n - 1];
}
int main()
{
	char symbols[] = "TTFT";
	char operators[] = "|&^";
	int n = strlen(symbols);

	// There are 4 ways
	// ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T))
	cout << countParenth(symbols, operators, n);
	return 0;
}