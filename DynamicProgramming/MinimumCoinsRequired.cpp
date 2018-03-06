#include<iostream>
using namespace std;
#define INF 999999
// similar to unbounded knapsack problem
int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}
void minimumCoins(int coins[], int n, int V)
{
	int *coin = new int[V + 1];
	int *track = new int[V + 1];
	for (int i = 0; i <= V; i++)
	{
		coin[i] = INF;   // to keep minimum coins required for V=0,1,2....V
		track[i] = -1;    // to keep the track of coins from where minimum is comming
	}
	coin[0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= V; j++)
		{
			if (j >= coins[i])           // coin will contribute to current sum required only if it is less than current sum required (current sum required ranges for j=0,1,2...V)
			{
				if (coin[j - coins[i]] != INF)
				{
					coin[j] = min(coin[j], coin[j - coins[i]] + 1);   // minimum from if we select this coin and if we do not select for this particular required sum. coin[j - coins[i]] denotes minum coins required if we select this coin i(i.e. if current required sum is j then minimum coins required for (j-value of coin i)
					if (coin[j] == coin[j - coins[i]] + 1)
						track[j] = i;  //update where this minimum comes from
				}
			}
		}
	}
	cout << "minimum no of coins required  is : " << coin[V] << "\n";
	int i = V;
	cout << "coins are \n";
	while (track[i] != -1)
	{
		cout << coins[track[i]] << " ";
		i = i - coins[track[i]];
	}
}
int main()
{
	int coins[] = { 9, 6, 5, 1 };
	int m = sizeof(coins) / sizeof(coins[0]);
	int V = 11;
	minimumCoins(coins, m, V);
	return 0;
}