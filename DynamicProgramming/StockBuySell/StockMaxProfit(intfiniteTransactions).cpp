/*
The cost of a stock on each day is given in an array, find the max profit that you can make by buying and selling in those days. 
For example, if the given array is {100, 180, 260, 310, 40, 535, 695}, the maximum profit can earned by buying on day 0, selling on day 3. 
Again buy on day 4 and sell on day 6. If the given array of prices is sorted in decreasing order, then profit cannot be earned at all.

Following is algorithm for this problem.
1. Find the local minima and store it as starting index. If not exists, return.
2. Find the local maxima. and store it as ending index. If we reach the end, set the end as ending index.
3. Update the solution (Increment count of buy sell pairs)
4. Repeat the above steps if end is not reached.

*/
#include<iostream>
#include<vector>
using namespace std;

void stockBuySell(int arr[], int n)
{
	int max_profit = 0;
	int i = 0;
	int localmin = -1;
	int localmax = -1;
	vector<pair<pair<int, int>, int>> store;
	while (i < n)
	{
		//find local minimum
		while (i < n - 1 && arr[i + 1] <= arr[i])
			i++;
		if (i == n - 1)
			break;
		localmin = i;
		i++;
		//find local maximum
		while (i < n&&arr[i] >= arr[i - 1])
			i++;
		i--;
		localmax = i;
		// store the local maximum and minimum
		store.push_back(make_pair(make_pair(localmin, localmax), arr[localmax] - arr[localmin]));
	}
	if (localmin == -1)
		cout << "maximum profit is : " << max_profit << "\n";
	else
	{
		vector<pair<pair<int, int>, int>>::iterator it;
		for (it = store.begin(); it != store.end(); it++)
		{
			max_profit += (*it).second;
			cout << "buy on day : " << (*it).first.first << " and sell on day : " << (*it).first.second << "\n";
		}
		cout << "maximum profit is : " << max_profit << "\n";
	}
}
int main()
{
	int price[] = { 100, 180, 260, 310, 40, 535, 695 };
	int n = sizeof(price) / sizeof(price[0]);

	// fucntion call
	stockBuySell(price, n);
}