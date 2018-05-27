// C++ program to print all palindromic partitions
// of a given string.
#include <iostream>
#include<vector>
#include<string>
using namespace std;

// Returns true if str is palindrome, else false
bool checkPalindrome(string str)
{
	int len = str.length();
	len--;
	for (int i = 0; i<len; i++)
	{
		if (str[i] != str[len])
			return false;
		len--;
	}
	return true;
}

void printUtil(string s, vector<string> &v, int n, int index)
{
	if (index == n)
	{
		vector<string>::iterator it;
		for (it = v.begin(); it != v.end(); it++)
		{
			cout << *it << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; index+ i < n; i++)
	{
		string str = s.substr(index, i + 1);
		if (checkPalindrome(str))
		{
			v.push_back(str);
			printUtil(s, v, n, index+i + 1);
			v.pop_back();
		}
	}
}
// Generates all palindromic partitions of 's' and
// stores the result in 'v'.
void partition(string s)
{
	vector<string> temp;
	printUtil(s, temp, s.length(), 0);
	return;
}

// Driver code
int main()
{
	string s = "geeks";
	partition(s);
	return 0;
}