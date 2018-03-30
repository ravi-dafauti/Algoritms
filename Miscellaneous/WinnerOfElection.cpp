/*
Given an array of names of candidates in an election. A candidate name in array represents a vote casted to the candidate. Print the name of candidate that received Max votes. If there is tie, print lexicographically smaller name.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. Then T test case follows. Each testcase contains two lines:-
The number of votes cast N
The name of the candidates separated by a space. Each name represents one vote casted to that candidate.

Output:
For each testcase, print the name of the candidate with the maximum votes, and also print the votes casted for the candidate. The name and votes are separated by a space.

Constraints:
1<=T<=105
1<=N<=1000

Example:

Input:
2
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john
3
andy blake clark

Output:
john 4
andy 1
*/
#include<iostream>
#include<string>
using namespace std;

void printWinner(string *s,int n)
{
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int *count = new int[n];
	for (int i = 0; i < n; i++)
		count[i] = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != "")
		{
			count[i] = 1;
			for (int j = i + 1; j < n; j++)
			{
				if (s[i] == s[j])
				{
					count[i]++;
					s[j] = "";
				}
			}
		}
	}
	int index = 0;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (count[i] > max)
		{
			max = count[i];
			index = i;
		}
		if (count[i] == max)
		{
			if (s[i] < s[index])
				index = i;
		}
	}
	cout << s[index] << " " << max << "\n";
}
int main()
{
	string s;
	int TestCase;
	cin >> TestCase;
	while (TestCase)
	{
		int n;
		cin >> n;
		string *s = new string[n];
		printWinner(s, n);
		TestCase--;
	}
    return 0;
}

