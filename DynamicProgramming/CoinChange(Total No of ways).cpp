/*Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm }
 valued coins, how many ways can we make the change ? The order of coins doesn’t matter.

For example, for N = 4 and S = { 1,2,3 }, there are four solutions : {1, 1, 1, 1}, { 1,1,2 }, { 2,2 }, { 1,3 }.
So output should be 4. For N = 10 and S = { 2, 5, 3, 6 }, there are five solutions : {2, 2, 2, 2, 2}, { 2,2,3,3 }, { 2,2,6 }, { 2,3,5 } and {5, 5}.
So the output should be 5.*/

#include<iostream>
using namespace std;

int coinChange(int arr[], int n, int V)
{
	int *count = new int[V + 1];
	for (int i = 0; i <= V; i++)
		count[i] = 0;
	count[0] = 1; // there is one way to select no coin to make 0 sum
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= V; j++)
		{
			if (arr[i] <= j)
			{
				count[j] += count[j - arr[i]];   // sum of ways by not including i ie. count[j] and by including i i.e count[j-arr[i]]
			}
		}
	}
	return count[V];
}
int main()
{
	int arr[] = { 1, 2, 3 };
	int m = sizeof(arr) / sizeof(arr[0]);
	int n = 4;
	cout << coinChange(arr, m, n);
	return 0;
}