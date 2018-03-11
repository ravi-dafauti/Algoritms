/*
Given N jobs where every job is represented by following three elements of it.

Start Time
Finish Time
Profit or Value Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.

Example:

Input: Number of Jobs n = 4
Job Details {Start Time, Finish Time, Profit}
Job 1:  {1, 2, 50}
Job 2:  {3, 5, 20}
Job 3:  {6, 19, 100}
Job 4:  {2, 100, 200}
Output: The maximum profit is 250.
We can get the maximum profit by scheduling jobs 1 and 4.
Note that there is longer schedules possible Jobs 1, 2 and 3
but the profit with this schedule is 20+50+100 which is less than 250.
*/
#include<iostream>
using namespace std;
struct Job
{
	int start, finish, profit;
};
// sorts job on basis on end time
void sortJob(Job arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i; j < n; j++)
		{
			if (arr[min].finish > arr[j].finish)
			{
				min = j;
			}
		}
		if (min != i)
		{
			Job temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int findMaxProfit(Job arr[], int n)
{
	sortJob(arr, n);
	int *DP = new int[n];
	for (int i = 0; i < n; i++)
		DP[i] = arr[i].profit;
	int max_prof = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j].finish <= arr[i].start)
			{
				DP[i] = max(DP[i], DP[j] + arr[i].profit);
				if (max_prof < DP[i])
					max_prof = DP[i];
			}
		}
	}
	return max_prof;
}
int main()
{
	Job arr[] = { { 3, 10, 20 },{ 1, 2, 50 },{ 6, 19, 100 },{ 2, 100, 200 } };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The optimal profit is " << findMaxProfit(arr, n);
	return 0;
}