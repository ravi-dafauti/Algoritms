/*
Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. 
It is also given that every job takes single unit of time, so the minimum possible deadline for any job is 1. How to maximize total profit if only one job can be scheduled at a time.

Examples:

Input: Four Jobs with following deadlines and profits
JobID    Deadline      Profit
a        4            20
b        1            10
c        1            40
d        1            30
Output: Following is maximum profit sequence of jobs
c, a


Input:  Five Jobs with following deadlines and profits
JobID     Deadline     Profit
a         2           100
b         1           19
c         2           27
d         1           25
e         3           15
Output: Following is maximum profit sequence of jobs
c, a, e

Greedy algorithm for the problem
1) Sort all jobs in decreasing order of profit.
2) Initialize the result sequence as first job in sorted jobs.
3) Do following for remaining n-1 jobs
.......a) If the current job can fit in the current result sequence
without missing the deadline, add current job to the result.
Else ignore the current job.
*/
#include<iostream>
#include<algorithm>
using namespace std;

struct Job
{
	char id;      // Job Id
	int dead;    // Deadline of job
	int profit;  // Profit if job is over before or on deadline
};

bool compare(Job a, Job b)
{
	return a.profit > b.profit;
}
void printJobScheduling(Job arr[], int n)
{
	int *sequence = new int[n + 1];
	for (int i = 0; i <= n; i++)
		sequence[i] = 0;  //sequence[i]=0 means slot i is empty
	// sort in decreasing order of profit
	sort(arr, arr + n, compare);
	for (int i = 0; i < n; i++)
	{
		int j = arr[i].dead;
		// for each job assign the last empty slot
		while (j > 0)
		{
			if (sequence[j] == 0)
			{
				sequence[j] = i + 1;
				break;
			}
			j--;
		}
	}
	for (int i = 0; i <= n; i++)
	{
		if (sequence[i] != 0)
		{
			cout << arr[sequence[i] - 1].id << " ";
		}
	}
}
int main()
{
	Job arr[] = { { 'a', 2, 100 },{ 'b', 1, 19 },{ 'c', 2, 27 },
	{ 'd', 1, 25 },{ 'e', 3, 15 } };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Following is maximum profit sequence of jobs\n";
	printJobScheduling(arr, n);
    return 0;
}

