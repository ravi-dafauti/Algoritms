/*Given an array of positive numbers, find the maximum sum of a subsequence with the constraint that no 2 numbers in the sequence should be adjacent in the array. 
So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).Answer the question in most efficient way.*/
#include<iostream>
using namespace std;
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int maxSum(int arr[], int n)
{
	int incl, excl;
	if (n == 1)
		return arr[0];
	else if (n == 2)
		return max(arr[0], arr[1]);
	else
	{
		incl = arr[0];
	    excl= max(arr[0], arr[1]);
		for (int i = 2; i < n; i++)
		{
			int temp = max(excl, arr[i] + incl);
			incl = excl;
			excl = temp;
		}
	}
	return excl;
}
int main()
{
	int arr[] = { 5, 5, 10, 100, 10, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum sum such that no two elements are adjacent is : " << maxSum(arr, size);
	return 0;
}