/*Given an input string and a dictionary of words, find out if the input
string can be segmented into a space-separated sequence of dictionary words. See following examples for more details.

Consider the following dictionary 
{ i, like, sam, sung, samsung, mobile, ice, 
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes 
The string can be segmented as "i like".
*/
#include <iostream>
#include <string>
using namespace std;

bool dictionaryContains(string word)
{
	string dictionary[] = { "mobile","samsung","sam","sung","man","mango",
		"icecream","and","go","i","like","ice","cream" };
	int size = sizeof(dictionary) / sizeof(dictionary[0]);
	for (int i = 0; i < size; i++)
		if (dictionary[i].compare(word) == 0)
			return true;
	return false;
}

// Returns true if string can be segmented into space separated
// words, otherwise returns false
bool wordBreak(string str)
{
	int size = str.size();
	if (size == 0)
		return true;
	bool **table = (bool **)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
		table[i] = (bool *)malloc(sizeof(bool)*size);
	for (int i = 0; i < size; i++)
	{
		if (dictionaryContains(str.substr(i,1)))
			table[i][i] = true;
		else
			table[i][i] = false;
	}
	int l;
	for (l = 2; l <= size; l++)
	{
		for (int i = 0; i + l - 1 < size; i++)
		{
			int j = i + l - 1;
			if (dictionaryContains(str.substr(i, l)))
			{
				table[i][j] = true;
			}
			else
			{
				for (int k = i; k < j; k++)
				{
					if (table[i][k] && table[k + 1][j])
					{
						table[i][j] = true;
						break;
					}
					else
					{
						table[i][j] = false;
					}
				}
			}
		}
	}
	return table[0][size - 1];
}

// Driver program to test above functions
int main()
{
	wordBreak("ilikesamsung") ? cout << "Yes\n" : cout << "No\n";
	wordBreak("iiiiiiii") ? cout << "Yes\n" : cout << "No\n";
	wordBreak("") ? cout << "Yes\n" : cout << "No\n";
	wordBreak("ilikelikeimangoiii") ? cout << "Yes\n" : cout << "No\n";
	wordBreak("samsungandmango") ? cout << "Yes\n" : cout << "No\n";
	wordBreak("samsungandmangok") ? cout << "Yes\n" : cout << "No\n";
	return 0;
}