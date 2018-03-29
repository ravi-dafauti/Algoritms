/*
Given an array of positive integers arr[] and a sum x, find all unique combinations in arr[] where the sum is equal to x. The same repeated number may be chosen from arr[] unlimited number of times. Elements in a combination (a1, a2, …, ak) must be printed in non-descending order. (ie, a1 <= a2 <= … <= ak).
The combinations themselves must be sorted in ascending order, i.e., the combination with smallest first element should be printed first. If there is no combination possible the print "Empty" (without quotes).

Examples:

Input : arr[] = 2, 4, 6, 8
x = 8
Output : [2, 2, 2, 2]
[2, 2, 4]
[2, 6]
[4, 4]
[8]
*/
#include<iostream>
#include<vector>
using namespace std;

void print(int arr[], int n, vector<int> &v, int &cs, int sum,int index)
{
	if (cs == sum)
	{
		vector<int>::iterator it;
		for (it = v.begin(); it != v.end(); it++)
			cout << *it << " ";
		cout << "\n";
		return;
	}
	for (int i = index; i < n && cs + arr[i] <= sum; i++)
	{
		v.push_back(arr[i]);
		cs = cs + arr[i];
		print(arr, n, v, cs, sum, i);
		cs = cs - arr[i];
		v.pop_back();
	}
}
int main()
{
	int arr[] = { 2,4,6,8 };
	int cs = 0;
	int s = 8;
	vector<int> v;
	print(arr, 4, v, cs, s, 0);
    return 0;
}

