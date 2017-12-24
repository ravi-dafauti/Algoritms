/*An expression will be given which can contain open and close parentheses and optionally some characters, 
No other operator will be there in string. We need to remove minimum number of parentheses to make the input string valid.
If more than one valid output are possible removing same number of parentheses then print all such output.*/

#include<iostream>
#include<queue>
#include<set>
#include<string>

using namespace std;

int isparantheses(char a)
{
	if (a == '(' || a == ')')
	{
		return 1;
	}
	return 0;
}
int isValidString(string str)
{
	int c = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
			c++;
		if (str[i] == ')')
			c--;
		if (c < 0)
			return 0;
	}
	return c == 0 ? 1 : 0;
}
void removeInvalidParenthesis(string str)
{
	set<string> setofstring;
	queue<string> bfs;
	bfs.push(str);
	int level = 0;
	while (!bfs.empty())
	{
		string s = bfs.front();
		bfs.pop();
		if (isValidString(s))
		{
			cout << s << "\n";
			level = 1;
		}
		if (level)
			continue;
		for (int i = 0; i < s.length(); i++)
		{
			if (!isparantheses(str[i]))
				continue;
			string temp = s.substr(0, i) + s.substr(i + 1);
			if (setofstring.find(temp) == setofstring.end())
			{
				bfs.push(temp);
				setofstring.insert(temp);
			}
		}
	}
}
int main()
{
	string expression = "()())()";
	removeInvalidParenthesis(expression);

	expression = "()v)";
	removeInvalidParenthesis(expression);
    return 0;
}

