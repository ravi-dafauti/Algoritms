/*
Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.

Examples :

Input : X = "GeeksforGeeks", y = "GeeksQuiz"
Output : 5
The longest common substring is "Geeks" and is of
length 5.

Input : X = "abcdxyz", y = "xyzabcd"
Output : 4
The longest common substring is "abcd" and is of
length 4.
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
void longestCommonSubstring(char X[], char Y[], int m, int n)
{
	int **table = (int **)malloc(sizeof(int)*(m + 1));
	for (int i = 0; i <= m; i++)
		table[i] = (int *)malloc(sizeof(int)*(n + 1));
	for (int i = 0; i <= m; i++)
		table[i][0] = 0;
	for (int i = 1; i <= n; i++)
		table[0][i] = 0;
	int maxlenght = 0;
	int maxi, maxj;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (X[i - 1] == Y[j - 1])
			{
				table[i][j] = 1 + table[i - 1][j - 1];
				if (maxlenght < table[i][j])
				{
					maxlenght = table[i][j];
					maxi = i;
					maxj = j;
				}

			}
			else
			{
				table[i][j] = 0;
			}
		}
	}
	cout << "maximum lenght of maximum substring : " << maxlenght << "\n";
	cout << "maximum substring is : ";
	stack<char> s;
	while (table[maxi][maxj] != 0)
	{
		s.push(X[maxi - 1]);
		maxi--;
		maxj--;
	}
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}
int main()
{
	char X[] = "ABCXYZGQ";
	char Y[] = "BBCXAZGNML";

	int m = strlen(X);
	int n = strlen(Y);

	longestCommonSubstring(X, Y, m, n);

	return 0;
}