#include<iostream>
#include<vector>
#include<string>
using namespace std;

void printSol(vector<vector<string>> &con)
{
	for (int i = 0; i < con.size(); i++)
	{
		for (int j = 0; j < con[i].size(); j++)
		{
			cout << con[i][j] << " ";
		}
		cout << "\n";
	}
}

bool isPalindrome(string s)
{
	int i, j;
	for (i = 0, j = s.length() - 1; i < j; i++, j--)
	{
		if (s[i] != s[j])
		{
			return false;
		}
	}
	return true;
}
void recur(string &s, vector < vector<string>> &con, vector<string> &temp, int index)
{
	string str;
	vector<string> curr = temp;
	/*if (index == 0)
	{
		temp.clear();
	}*/
	for (int i = index; i < s.length(); i++)
	{
		str = str + s[i];
		if (isPalindrome(str))
		{
			temp.push_back(str);
			if (i + 1 < s.size())
			{
				recur(s, con, temp, i + 1);
			}
			else
			{
				con.push_back(temp);
			}
			temp = curr;
		}
	}
	return;
}
void printPart(string &s, vector<vector<string>> &con)
{
	vector<string> temp;
	recur(s, con, temp, 0);
	printSol(con);
}
int main()
{
	string s = "geeks";
	vector<vector<string>> container;
	printPart(s, container);
	return 0;
}