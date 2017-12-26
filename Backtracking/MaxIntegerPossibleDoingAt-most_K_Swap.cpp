// MaxIntegerPossibleDoingAt-most_K_Swap.cpp : Defines the entry point for the console application.
//

/*Given a positive integer, find maximum integer possible by doing at-most K swap operations on its digits.*/

#include<iostream>
#include<string>

using namespace std;

void findMaximumNum(string &str, int k, string &max)
{
	if (k == 0)
	{
		return;
	}

	for (int i = 0; i < str.length() - 1; i++)
	{
		for (int j = i + 1; j < str.length(); j++)
		{
			if (str[i] < str[j])
			{
				swap(str[i], str[j]);
				if (str.compare(max) > 0)
				{
					max = str;
				}
				findMaximumNum(str, k - 1, max);
				swap(str[i], str[j]);
			}
		}
	}
}
int main()
{
	string str = "129814999";

	int k = 5;

	string max = str;
	findMaximumNum(str, k, max);

	cout << max << endl;
    return 0;
}

