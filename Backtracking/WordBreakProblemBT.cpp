// C++ program to print all palindromic partitions
// of a given string.
#include <iostream>
#include<vector>
#include<string>
using namespace std;

int dictionaryContains(string &word)
{
	string dictionary[] = { "mobile","samsung","sam","sung",
		"man","mango", "icecream","and",
		"go","i","love","ice","cream" };
	int n = sizeof(dictionary) / sizeof(dictionary[0]);
	for (int i = 0; i < n; i++)
		if (dictionary[i].compare(word) == 0)
			return true;
	return false;
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
	for (int i = 0; index + i < n; i++)
	{
		string str = s.substr(index, i + 1);
		if (dictionaryContains(str))
		{
			v.push_back(str);
			printUtil(s, v, n, index + i + 1);
			v.pop_back();
		}
	}
}



// Prints all possible word breaks of given string
void wordBreak(string str)
{
	vector<string> temp;
	printUtil(str, temp, str.length(), 0);
}

int main()
{
	cout << "First Test:\n";
	wordBreak("iloveicecreamandmango");

	cout << "\nSecond Test:\n";
	wordBreak("ilovesamsungmobile");
	return 0;
}