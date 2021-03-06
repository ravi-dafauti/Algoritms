/*
Given strings s1 and s2, you need to find if s2 is a rotated version of the string s1. The strings are lowercase.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. Then T test case follows. Each testcase contains two lines for s1 and s2.

Output:
For each testcase, you need to print 1 if s2 is a rotated version of s1; else print 0.

Constraints:
1<=T<=100
1<=|s1|,|s2|<=100

Example:

Input:
4
geeksforgeeks
forgeeksgeeks
mightandmagic
andmagicmigth
mushroomkingdom
itsamemario
geekofgeeks
geeksgeekof

Output:
1
0
0
1
*/
#include<iostream>
#include<string>
using namespace std;

bool isRoatation(string s1, string s2)
{
	string s = s2;
	s += s2;
	if (s1.length()==s2.length() && s.find(s1) != string::npos)
		return true;
	return false;
}

int main()
{
	char s1[101];
	char s2[101];
	int TestCase;
	cin >> TestCase;
	while (TestCase)
	{
		cin >> s1;
		cin >> s2;
		if (isRoatation(s1, s2))
		{
			cout << 1 << "\n";
		}
		else
			cout << 0 << "\n";
		TestCase--;
	}
    return 0;
}

