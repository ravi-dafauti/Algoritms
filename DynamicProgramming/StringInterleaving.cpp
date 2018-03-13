/*
Given three strings A, B and C. Write a function that checks whether C is an interleaving of A and B. 
C is said to be interleaving A and B, if it contains all characters of A and B and order of all characters in individual strings is preserved.
*/
#include<iostream>
using namespace std;

bool isInterleaved(char *A, char * B, char *C)
{
	bool **dp = (bool **)malloc(sizeof(int)*(strlen(A) + 1));
	for (int i = 0; i < strlen(A) + 1; i++)
		dp[i] = (bool *)malloc(sizeof(bool)*(strlen(B) + 1));
	for (int i = 0; i < strlen(A) + 1; i++)
	{
		if (i == 0 || ((A[i - 1] == C[i - 1]) && dp[i - 1][0] == true))
			dp[i][0] = true;
		else
			dp[i][0] = false;
	}
	for (int i = 1; i < strlen(B) + 1; i++)
	{
		if (B[i - 1] == C[i - 1] && dp[0][i - 1] == true)
			dp[0][i] = true;
		else
			dp[0][i] = false;
	}
	for (int i = 1; i <= strlen(A); i++)
	{
		for (int j = 1; j <= strlen(B); j++)
		{
			if (C[i + j - 1] != A[i - 1] && C[i + j - 1] != B[j - 1])
				dp[i][j] = false;
			else
			{
				if (C[i + j - 1] == A[i - 1])
				{
					if (dp[i - 1][j] == true)
						dp[i][j] = true;
					else
						dp[i][j] = false;
				}
				else if (C[i + j - 1] == B[j - 1])
				{
					if (dp[i][j - 1] == true)
						dp[i][j] = true;
					else
						dp[i][j] = false;
				}
			}
		}
	}
	return dp[strlen(A)][strlen(B)];
}
void test(char *A, char *B, char *C)
{
	if (isInterleaved(A, B, C))
		cout << C << " is interleaved of " << A << " and " << B << endl;
	else
		cout << C << " is not interleaved of " << A << " and " << B << endl;
}
int main()
{
	test("XXY", "XXZ", "XXZXXXY");
	test("XY", "WZ", "WZXY");
	test("XY", "X", "XXY");
	test("YX", "X", "XXY");
	test("XXY", "XXZ", "XXXXZY");
	return 0;
}