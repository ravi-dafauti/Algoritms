// CombinationalSum.cpp : Defines the entry point for the console application.
//
/*Given an array of positive integers arr[] and a sum x, find all unique combinations in arr[] where the sum is equal to x. The same repeated number may be chosen from arr[] unlimited number of times. Elements in a combination (a1, a2, …, ak) must be printed in non-descending order. (ie, a1 <= a2 <= … <= ak).
The combinations themselves must be sorted in ascending order, i.e., the combination with smallest first element should be printed first. If there is no combination possible the print "Empty" (without quotes).*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool myfunction(int i, int j) { return (i<j); }

void printSol(vector<int> &temp)
{
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i] << " ";
	}
	cout << "\n";
}
void recur(vector<int> &arr, vector<int> &temp, int n, int sum, int index, int currSum,int indexmain)
{
	if (currSum == sum)
	{
		printSol(temp);
		return;
	}
	for (int i = indexmain; i < arr.size() && (currSum + arr[i] <= sum); i++)
	{
		temp.push_back(arr[i]);
		recur(arr, temp, n, sum, index + 1, currSum + arr[i], i);
		temp.pop_back();
	}
}
void combinationalSum(vector<int> &arr, int n, int sum)
{
	//array for storing result, use vector instead as size is not known before.
   // int temp[1000];
	vector<int> temp;
	sort(arr.begin(), arr.end());
	recur(arr, temp, n, sum, 0, 0, 0);
}
int main()
{
	int arr[] = { 2, 4, 6, 8 };
	int size = sizeof(arr) / sizeof(int);
	vector<int> store;
	for (int i = 0; i < size; i++)
	{
		store.push_back(arr[i]);
	}
	int sum = 8;
	combinationalSum(store, size, 8);
}

