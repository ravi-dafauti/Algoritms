/*Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. 
Determine the maximum value obtainable by cutting up the rod and selling the pieces.
For example, if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)


length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20*/

#include<iostream>
using namespace std;
#define INF -999999
// similar to unbounded knapsack problem
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
void rodCutting(int arr[], int n)
{
	int *value = new int[n + 1];
	int *elements = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		value[i] = INF;
		elements[i] = -1;
	}
	value[0] = 0; // for lenght 0 max value is 0
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j >= i && (value[j - i] + arr[i - 1])!=INF)  
			{
				value[j] = max(value[j], value[j - i] + arr[i - 1]); // take maximum of value obtained by selecting i ie.value[j - i] + arr[i - 1] or not selecting i i.e value[j]
				if (value[j - i] + arr[i - 1] == value[j])
					elements[j] = i; // keep track of element
			}
		}
	}

	cout << "maximum value that can be made is : " << value[n] << "\n";
	cout << "lenghts are : \n";
	int i = n;
	while (elements[i] != -1)
	{
		cout << elements[i] << " ";
		i = i - elements[i];
	}
}
int main()
{
	int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	int size = sizeof(arr) / sizeof(arr[0]);
	rodCutting(arr, size);
	return 0;
}