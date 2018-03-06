/*Given an array of integers where each element represents the max number of steps that can be made forward from that element.
Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Example:

Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 8 ->9)*/

#include<iostream>
using namespace std;

#define MAX 999999
int minJumps(int arr[], int n)
{
	int *jump = new int[n];
	for (int i = 0; i < n; i++)
		jump[i] = MAX;
	jump[0] = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (j + arr[j] >= i)
			{
				if (1 + jump[j] < jump[i])
				{
					jump[i] = 1 + jump[j];
				}
			}
		}
	}
	return jump[n - 1];
}
int main()
{
	int arr[] = { 1, 3, 6, 3, 2, 3, 6, 8, 9, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Minimum number of jumps to reach end is : " << minJumps(arr, n);
	return 0;
}