/*
In this problem, a String is composed of lowercase alphabets and wildcard characters i.e. '?'. Here, '?' can be replaced by any of the lowercase alphabets. Now you have to classify the given String on the basis of following rules:

If there are more than 3 consonants together or more than 5 vowels together, the String is considered to be "BAD". A String is considered "GOOD" only if it is not “BAD”.

NOTE: String is considered as "BAD" if the above condition is satisfied even once. Else it is "GOOD".

Input:
The first line consists of an integer T i.e number of test cases. The first and only line of each test case consists of a string s.

Output:
If the string is GOOD,  Print "1"  else print "0".

Constraints:
1<=T<=100
1<=|Length of string|<=100

Example:
Input:
2
aeioup??
bcdaeiou??

Output:
1
0
*/
#include<iostream>
using namespace std;

bool isVowel(char a)
{
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		return true;
	return false;
}
bool printGB(char *str, int n)
{
	int *temp = new int[n];
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '?' || isVowel(str[i]))
		{
			if (i == 0)
				temp[i] = 1;
			else
			{
				temp[i] = temp[i - 1] + 1;
			}
		}
		else
			temp[i] = 0;
		if (temp[i] > 5)
			return false;
	}
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '?' || !isVowel(str[i]))
		{
			if (i == 0)
				temp[i] = 1;
			else
			{
				temp[i] = temp[i - 1] + 1;
			}
		}
		else
			temp[i] = 0;
		if (temp[i] > 3)
			return false;
	}
	return true;

}
int main()
{
	int t;
	cin >> t;
	char str[101];
	while (t)
	{
		cin >> str;
		if (printGB(str, strlen(str)))
			cout << 1;
		else
			cout << 0;
		cout << "\n";
		t--;
	}
    return 0;
}

