/*
Given an array containing N words, you need to find the most frequent word in the array. If multiple words have same frequency then print the word that comes first in lexicographical order.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. Then T test case follows. Each test case contains 2 lines:-
The size of array N
N words separated by spaces

Output:
For each testcase, print the most frequent word.

Constraints:
1<=T<=100
1<=N<=1000

Example:

Input:
3
3
geeks for geeks
2
hello world
3
world wide fund

Output:
geeks
hello
fund
*/
#include<iostream>
#include<string>
using namespace std;

void printMostFrequent(string *s, int n)
{

}
int main()
{
	int TestCase;
	cin >> TestCase;
	while (TestCase)
	{
		int n;
		cin >> n;
		string *s = new string[n];
		printMostFrequent(s, n);
		TestCase--;
	}
    return 0;
}

