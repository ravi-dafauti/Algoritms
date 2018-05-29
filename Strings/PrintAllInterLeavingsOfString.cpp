/*
Given two strings str1 and str2, write a function that prints all interleavings of the given two strings. You may assume that all characters in both strings are different

Example:

Input: str1 = "AB",  str2 = "CD"
Output:
ABCD
ACBD
ACDB
CABD
CADB
CDAB

Input: str1 = "AB",  str2 = "C"
Output:
ABC
ACB
CAB
*/
#include<iostream>
#include<string>
using namespace std;
void printIls(char *a, char *b, int m, int n, string &s)
{
	if (m == 0 && n == 0)
	{
		cout << s;
		cout << "\n";
	}
	if (m != 0)
	{
		s.push_back(a[0]);
		printIls(a + 1, b, m - 1, n, s);
		s.pop_back();
	}
	if (n != 0)
	{
		s.push_back(b[0]);
		printIls(a, b + 1, m, n - 1, s);
		s.pop_back();
	}
}
int main()
{
	char str1[] = "AB";
	char str2[] = "CD";
	string s = "";
	printIls(str1, str2, strlen(str1), strlen(str2), s);
}

