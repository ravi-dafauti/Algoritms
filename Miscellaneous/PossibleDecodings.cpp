/*
Let 1 represent ‘A’, 2 represents ‘B’, etc. Given a digit sequence, count the number of possible decodings of the given digit sequence.

Examples:

Input:  digits[] = "121"
Output: 3
// The possible decodings are "ABA", "AU", "LA"

Input: digits[] = "1234"
Output: 3
// The possible decodings are "ABCD", "LCD", "AWD"
An empty digit sequence is considered to have one decoding. It may be assumed that the input contains valid digits from 0 to 9 and there are no leading 0’s, no extra trailing 0’s and no two or more consecutive 0’s.
*/

#include<iostream>
using namespace std;
int countUtil(char digits[], int dp[], int n)
{
	if (dp[n])
		return dp[n];
	if (n == 0 || n == 1)
		dp[n] = 1;
	else
	{
		int count = 0;
		if (digits[n - 1] != '0')
			count = countUtil(digits, dp, n - 1);
		if (digits[n - 2] == '1' || (digits[n - 2] == '2'&& digits[n-1]>='0' && digits[n - 1] <= '6'))
		{
			count+= countUtil(digits, dp, n - 2);
		}
		dp[n] = count;
	}
	return dp[n];
}
int countDecodingDP(char digits[], int n)
{
	int *dp = new int[n + 1];
	for (int i = 0; i <= n; i++)
		dp[i] = 0;
	return countUtil(digits, dp, n);
}
int main()
{
	char digits[] = "1234";
	int n = strlen(digits);
	cout << "Count is " << countDecodingDP(digits, n);
    return 0;
}

