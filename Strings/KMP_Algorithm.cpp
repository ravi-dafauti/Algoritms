#include<iostream>
#include<string>
using namespace std;

void findprefixArray(string P, int arr[])
{
	arr[0] = 0;
	int i = 1;
	int j = 0;
	while (i < P.length())
	{
		if (P[i] == P[j])
		{
			arr[i] = j + 1;
			i++;
			j++;
		}
		else if (j > 0)
		{
			j = arr[j - 1];
		}
		else
		{
			arr[i] = 0;
			i++;
		}
	}
}
void KMPSearch(string T, string P)
{
	int *prefixArray = new int[P.length()];
	findprefixArray(P, prefixArray);
	int i = 0;
	int j = 0;
	int ans = -1;
	while (i < T.length())
	{
		if (T[i] == P[j])
		{
			if (j == (P.length() - 1))
			{
				ans = (i - j);
				break;
			}
			i++;
			j++;
		}
		else if (j > 0)
		{
			j = prefixArray[j - 1];
		}
		else
		{
			i++;
		}
	}
	cout << "found at index " << ans;
}
int main()
{
	string txt = "ABABDABACDABABCABAB";
	string pat = "ABABCABAB";
	KMPSearch(txt, pat);
	return 0;
}