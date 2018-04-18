#include<iostream>
#include<string>
using namespace std;

#define prime 101
int calculateHash(string s, int m)
{
	int hash = 0;
	for (int i = 0; i < m; i++)
	{
		hash += s[i] * pow(prime, i);
	}
	return hash;
}
int recalculateHash(string s, int oldhash, int i, int m)
{
	oldhash = oldhash - s[i];
	oldhash /= prime;
	oldhash += s[i + m - 1] * pow(prime, m - 1);
	return oldhash;
}

void RabinKarp(string T, string P)
{
	int ans = -1;
	int hashP = calculateHash(P, P.length());
	int hashT;
	for (int i = 0; i <= T.length() - P.length(); i++)
	{
		if (i == 0)
		{
			hashT = calculateHash(T, P.length());
		}
		else
		{
			hashT = recalculateHash(T, hashT, i, P.length());
		}
		if (hashP == hashT)
		{
			int flag = 0;
			for (int j = i, k = 0; k < P.length(); j++, k++)
			{
				if (T[j] != P[k])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				ans = i;
				break;
			}
		}
	}
	cout << "index found is : " << ans;
}
int main()
{
	string txt = "ABABDABACDABABCABAB";
	string pat = "ABABCABAB";
	RabinKarp(txt, pat);
	return 0;
}