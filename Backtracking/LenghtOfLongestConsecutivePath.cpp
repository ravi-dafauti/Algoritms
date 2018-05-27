/*
Given a matrix of characters. Find length of the longest path from a given character, such that all characters in the path are consecutive to each other, i.e., every character in path is next to previous in alphabetical order. It is allowed to move in all 8 directions from a cell.
Input: mat[][] = { {a, c, d},
{h, b, e},
{i, g, f}}
Starting Point = 'e'

Output: 5
If starting point is 'e', then longest path with consecutive
characters is "e f g h i".

Input: mat[R][C] = { {b, e, f},
{h, d, a},
{i, c, a}};
Starting Point = 'b'

Output: 1
'c' is not present in all adjacent cells of 'b'
*/
#include<iostream>
#define R 3
#define C 3
using namespace std;

// tool matrices to recur for adjacent cells.
int x[] = { 0, 1, 1, -1, 1, 0, -1, -1 };
int y[] = { 1, 0, 1, 1, -1, -1, 0, -1 };

// dp[i][j] Stores length of longest consecutive path
// starting at arr[i][j].
int dp[R][C];

// check whether mat[i][j] is a valid cell or not.
bool isvalid(int i, int j)
{
	if (i < 0 || j < 0 || i >= R || j >= C)
		return false;
	return true;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
// Check whether current character is adjacent to previous
// character (character processed in parent call) or not.
bool isadjacent(char prev, char curr)
{
	return ((curr - prev) == 1);
}

// i, j are the indices of the current cell and prev is the
// character processed in the parent call.. also mat[i][j]
// is our current character.
int getLenUtil(char mat[R][C], int i, int j)
{
	if (i >= R || i < 0 || j < 0 || j >= C)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	int ans = 0;
	for (int k = 0; k < 8; k++)
	{
		if (isvalid(i + x[k], j + y[k]) && isadjacent(mat[i][j], mat[i + x[k]][j + y[k]]))
		{
			ans = max(ans, 1 + getLenUtil(mat, i + x[k], j + y[k]));
		}
	}
	if (ans == 0)
		dp[i][j] = 1;
	else
		dp[i][j] = ans;
	return dp[i][j];

}

// Returns length of the longest path with all characters consecutive
// to each other.  This function first initializes dp array that
// is used to store results of subproblems, then it calls
// recursive DFS based function getLenUtil() to find max length path
int getLen(char mat[R][C], char s)
{
	memset(dp, -1, sizeof dp);
	int ans = 0;

	for (int i = 0; i<R; i++)
	{
		for (int j = 0; j<C; j++)
		{
			if (mat[i][j] == s) {
				if (dp[i][j] == -1)
				{
					dp[i][j] = getLenUtil(mat, i, j);
				}
				ans = max(ans, dp[i][j]);
			}
		}
	}
	return ans;
}

// Driver program
int main() {

	char mat[R][C] = { { 'a','c','d' },
	{ 'h','b','a' },
	{ 'i','g','f' } };

	cout << getLen(mat, 'a') << endl;
	cout << getLen(mat, 'e') << endl;
	cout << getLen(mat, 'b') << endl;
	cout << getLen(mat, 'f') << endl;
	return 0;
}