#include<iostream>
#include<string>
#include<vector>
using namespace std;
void permutationUtil(string s, int vis[], char per[], int index)
{
	if (index == s.length())
	{
		for (int i = 0; i <s.length(); i++)
		{
			cout << per[i];
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (vis[i])
			continue;
		vis[i] = 1;
		per[index] = s[i];
		permutationUtil(s, vis, per, index + 1);
		vis[i] = 0;
	}
}
void permutation(string s)
{
	int *vis = new int[s.length()];
	char *per = new char[s.length()];
	for (int i = 0; i < s.length(); i++)
		vis[i] = 0;
	permutationUtil(s, vis, per, 0);
}
void combinationUtil(string s, int vis[], int index)
{
	if (index == s.length())
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (vis[i] == 1)
				cout << s[i];
		}
		cout << "\n";
		return;
	}
	vis[index] = 0;
	combinationUtil(s, vis, index + 1);
	vis[index] = 1;
	combinationUtil(s, vis, index + 1);
}
void combination(string s)
{
	int *vis = new int[s.length()];
	for (int i = 0; i < s.length(); i++)
		vis[i] = 0;
	combinationUtil(s, vis, 0);
}
int main()
{
	string s = "abc";
	cout << "permutations\n";
	permutation(s);
	cout << "combinations\n";
	combination(s);
	return 0;
}