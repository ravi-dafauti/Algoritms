/*
An array is bitonic if it is comprises of an increasing sequence of integers followed immediately by a decreasing sequence of integers.
Given such a array, you need to find a element X in it and print its index.
In case, X does not exist in the array print "OOPS! NOT FOUND" without quotes.
Note: It is guaranteed that array consist of distinct elements. And array indexing is from 0.

Input:
First line will consist  a number T, the number of test cases.
Each test case will then consist of two numbers N and X. N being the array size and X being the element to be searched for.
Next line will consist of N space separated integers.


Output:
Print the required answer on separate lines.


Constraints:
1<=T<=100
1<=N<=200
-100<=A[i]<=100


Example:
Input:
1
5 2
1 2 7 4 3
Output:
1
*/

#include<iostream>
using namespace std;

int findbitonicPoint(int arr[], int l, int h)
{
	int mid = l + (h - l) / 2;
	if (l > h)
		return -1;
	if (l == h)
		return l;
	if (l + 1 == h)
	{
		if (arr[l] > arr[h])
			return l;
		return h;
	}
	if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
		return mid;
	if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
		return findbitonicPoint(arr, mid + 1, h);
	return findbitonicPoint(arr, l, mid - 1);
}
int binarySearch(int arr[], int l, int h, int x)
{
	if (l > h)
		return -1;
	int mid = l + (h - l) / 2;
	if (arr[mid] == x)
		return mid;
	else if (arr[mid] > x)
		return binarySearch(arr, l, mid - 1, x);
	return binarySearch(arr, mid + 1, h, x);
}
int find(int arr[], int n, int x)
{
	int index = findbitonicPoint(arr, 0, n - 1);
	if (arr[index] == x)
		return index;

	int l = binarySearch(arr, 0, index - 1, x);
	if (l != -1)
		return l;
	int r = binarySearch(arr, index + 1, n - 1, x);
	return r;
}
int main()
{
	int t;
	cin >> t;
	int n, x;
	int arr[205];
	while (t)
	{
		cin >> n >> x;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int index = find(arr, n, x);
		if (index != -1)
			cout << index;
		else
			cout << "OOPS! NOT FOUND";
		cout << "\n";
		t--;
	}
	return 0;
}

