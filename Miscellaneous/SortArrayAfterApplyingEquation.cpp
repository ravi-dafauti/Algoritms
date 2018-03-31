/*
Given a sorted integer array of size N, and 3 integers A, B and C. The task is to find and print a new array in sorted order(increasing) where
Ainew=A*Aiold*Aiold+B*Aiold+C

Input:
The first line of input contains T denoting the number of test cases.The first line of each test case contains three integers A, B, and C, as described above. The second line of each test case contains a single integer N, the size of the input array. The third line of each test case contains N-space separated integers, denoting the array.

Output:
For each test case output, a single line containing N-space separated integers, the elements of the new array in sorted order.

Constraints:
1<= T <= 1000
-105<= A,B,C <= 105
1<=N<=102
-105<= Ai <= 105

Example:
Input:

1
-1 2 -1
6
-1 0 1 2 3 4
Output:
-9 -4 -4 -1 -1 0

Explanation:
After sorting, we get {-9, -4, -4, -1, -1, 0}
After applying the equation A*x*x + B*x + C on every element x we get, {-4,-1, 0, -1, -4, -9}
Input array is {-1, 0, 1, 2, 3, 4}.
*/

#include<iostream>
using namespace std;
#define MIN 999999
#define MAX -999999
void fun(long long int arr[], int n, int A, int B, int C)
{
	long long int *newarr = new long long int[n];
	if (A >= 0)
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] = A*arr[i] * arr[i] + B*arr[i] + C;
		}
		long long int min = MIN;
		int minindex;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] < min)
			{
				minindex = i;
				min = arr[i];
			}
		}
		int i, j, k;
		k = 1;
		i = minindex - 1;
		j = minindex + 1;
		while (i>=0&&j<n)
		{
			if (arr[i] < arr[j])
			{
				newarr[k] = arr[i];
				i--;
				k++;
			}
			else
			{
				newarr[k] = arr[j];
				j++;
				k++;
			}
		}
		while (i >= 0)
		{
			newarr[k] = arr[i];
			i--;
			k++;
		}
		while (j < n)
		{
			newarr[k] = arr[j];
			j++;
			k++;
		}
		newarr[0] = min;
		for (int i = 0; i < n; i++)
			cout << newarr[i] << " ";
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] = A*arr[i] * arr[i] + B*arr[i] + C;
		}
		long long int max = MAX;
		int maxindex;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > max)
			{
				maxindex = i;
				max = arr[i];
			}
		}
		int i, j, k;
		k = 0;
		i = 0;
		j = n - 1;
		while (i <maxindex && j>maxindex)
		{
			if (arr[i] < arr[j])
			{
				newarr[k] = arr[i];
				i++;
				k++;
			}
			else
			{
				newarr[k] = arr[j];
				j--;
				k++;
			}
		}
		while (i <maxindex)
		{
			newarr[k] = arr[i];
			i++;
			k++;;
		}
		while (j>maxindex)
		{
			newarr[k] = arr[j];
			j--;
			k++;
		}
		newarr[n - 1] = max;
		for (int i = 0; i < n; i++)
			cout << newarr[i] << " ";
	}
}
int main()
{
	int t;
	cin >> t;
	int A, B, C;
	int N;
	long long int arr[105];
	while (t)
	{
		cin >> A >> B >> C;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		fun(arr, N, A, B, C);
		cout << "\n";
		t--;
	}
    return 0;
}

