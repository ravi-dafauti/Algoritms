/*
Majority Element: A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element).

Write a function which takes an array and emits the majority element (if it exists), otherwise prints NONE as follows:

I/P : 3 3 4 2 4 4 2 4 4
O/P : 4

I/P : 3 3 4 2 4 4 2 4
O/P : NONE
*/

#include<iostream>
using namespace std;
void printMajority(int arr[], int n)
{
	// find candidate for majority element
	int count = 0;
	int majority = -1;
	for (int i = 0; i < n; i++)
	{
		if (count == 0)
		{
			majority = arr[i];
			count = 1;
		}
		if (arr[i] == majority)
			count++;
		else
			count--;
	}
	// check if this is a majority element
	count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == majority)
			count++;
	}
	if (count > n / 2)
		cout << "majority element is : " << majority;
	else
		cout << "no majority element";
}
int main()
{
	int a[] = { 1, 3, 3, 1, 2,3,3,3 };
	int size = (sizeof(a)) / sizeof(a[0]);
	printMajority(a, size);
	return 0;
}