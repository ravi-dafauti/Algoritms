/*
Given arrival and departure times of all trains that reach a railway station, find the minimum number of platforms required for the railway station so that no train waits.
We are given two arrays which represent arrival and departure times of trains that stop

Examples:

Input:  arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
Output: 3
There are at-most three trains at a time (time between 11:00 to 11:20)
*/

#include<iostream>
#include<algorithm>
using namespace std;

int findPlatform(int arr[], int dept[], int n)
{
	//sort both arrivals and departure time
	sort(arr, arr + n);
	sort(dept, dept + n);
	int global = 0;
	int curr = 0;
	int i, j;
	i = j = 0;
	while (i < n && j < n)
	{
		//if next time is arrival increase number of platform
		if (arr[i] < dept[j])
		{
			curr++;
			if (curr > global)  // if current required platform is more then update total required platform
				global = curr;
			i++;
		}
		else   //if next time is decrease number of platform
		{
			if (curr == 0)
				return -1;
			curr--;
			j++;
		}
	}
	return global;
}
int main()
{
	int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
	int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Minimum Number of Platforms Required = " << findPlatform(arr, dep, n);
    return 0;
}

