/*In share trading, a buyer buys shares and sells on future date.Given stock price of n days,
the trader is allowed to make at most k transactions, where new transaction can only start after previous transaction is complete, 
find out maximum profit that a share trader could have made.
Input:
Price = [10, 22, 5, 75, 65, 80]
K = 2
Output : 87
	Trader earns 87 as sum of 12 and 75
	Buy at price 10, sell at 22, buy at
	5 and sell at 80

	Input :
	Price = [12, 14, 17, 10, 14, 13, 12, 15]
	K = 3
	Output : 12
	Trader earns 12 as sum of 5, 4 and 3
	Buy at price 12, sell at 17, buy at 10
	and sell at 14 and buy at 12 and sell
	at 15

*/

#include<iostream>
	using namespace std;
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int maxProfit(int price[], int n, int k)
{
	int **profit = (int **)malloc(sizeof(int)*(k + 1));
	for (int i = 0; i <= k; i++)
		profit[i] = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i <= k; i++)
		profit[i][0] = 0;
	for (int i = 0; i < n; i++)
		profit[0][i] = 0;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j < n; j++)
		{
			int max_cur = -999999;
			for (int m = 0; m < j; m++)
			{
				max_cur = max(max_cur, price[j] - price[m] + profit[i - 1][m]);
			}
			profit[i][j] = max(profit[i][j - 1], max_cur);
		}
	}
	return profit[k][n - 1];
}
int main()
{
	int k = 3;
	int price[] = { 12, 14, 17, 10, 14, 13, 12, 15 };

	int  n = sizeof(price) / sizeof(price[0]);

	cout << "Maximum profit is: " << maxProfit(price, n, k);

	return 0;
}