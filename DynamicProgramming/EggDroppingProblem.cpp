/*The following is a description of the instance of this famous puzzle involving n=2 eggs and a building with k=36 floors.

Suppose that we wish to know which stories in a 36-story building are safe to drop eggs from, and which will cause the eggs to break on landing. We make a few assumptions:

…..An egg that survives a fall can be used again.
…..A broken egg must be discarded.
…..The effect of a fall is the same for all eggs.
…..If an egg breaks when dropped, then it would break if dropped from a higher floor.
…..If an egg survives a fall then it would survive a shorter fall.
…..It is not ruled out that the first-floor windows break eggs, nor is it ruled out that the 36th-floor do not cause an egg to break.

If only one egg is available and we wish to be sure of obtaining the right result, the experiment can be carried out in only one way. Drop the egg from the first-floor window; if it survives, drop it from the second floor window. Continue upward until it breaks. In the worst case, this method may require 36 droppings. Suppose 2 eggs are available. What is the least number of egg-droppings that is guaranteed to work in all cases?
The problem is not actually to find the critical floor, but merely to decide floors from which eggs should be dropped so that total number of trials are minimized.*/

#include<iostream>
using namespace std;

#define MAX 999999
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int eggDropping(int n, int k)
{
	int **table = (int **)malloc(sizeof(int)*(n + 1));
	for (int i = 0; i <= n; i++)
		table[i] = (int *)malloc(sizeof(int)*(k + 1));
	for (int i = 0; i <= k; i++) {
		table[0][i] = 0;
		table[1][i] = i;
	}
	for (int i = 0; i <= n; i++)
		table[i][0] = 0;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (i > j)
				table[i][j] = table[i - 1][j];
			else
			{
				int min = MAX;
				for (int x = 1; x <= j; x++)
				{
					int temp = 1 + max(table[i - 1][x - 1], table[i][j - x]);
					if (temp < min)
						min = temp;
				}
				table[i][j] = min;
			}

		}
	}
	return table[n][k];
}
int main()
{
	int n = 2, k = 36;
	cout << "Minimum number of trials in worst case with " << n << " eggs and " << k << " floors is :" << eggDropping(n, k);
	return 0;
}