/*
Given that integers are read from a data stream. Find median of elements read so for in efficient way. For simplicity assume there are no duplicates. For example, let us consider the stream 5, 15, 1, 3 …

After reading 1st element of stream - 5 -> median - 5
After reading 2nd element of stream - 5, 15 -> median - 10
After reading 3rd element of stream - 5, 15, 1 -> median - 5
After reading 4th element of stream - 5, 15, 1, 3 -> median - 4, so on...
*/

#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using  namespace std;

void printMedian(int arr[], int n)
{
	priority_queue<int> max_q;
	priority_queue<int, vector<int>, greater<int>> min_q;
	for (int i = 0; i < n; i++)
	{
		if (max_q.empty())
			max_q.push(arr[i]);
		else
		{
			if (arr[i] > max_q.top())
			{
				min_q.push(arr[i]);
				if (max_q.size() + 1 <= min_q.size())
				{
					max_q.push(min_q.top());
					min_q.pop();
				}
			}
			else
			{
				max_q.push(arr[i]);
				if (max_q.size() > min_q.size() + 1)
				{
					min_q.push(max_q.top());
					max_q.pop();
				}
			}
		}

		if ((i + 1) % 2 == 0)
		{
			cout << (max_q.top() + min_q.top()) / 2 << "\n";
		}
		else
			cout << max_q.top() << "\n";
	}
}
int main()
{
	int A[] = { 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4 };
	int size = sizeof(A) / sizeof(A[0]);

	printMedian(A, size);
    return 0;
}

