/*
Equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes. For example, in an arrya A:

A[0] = -7, A[1] = 1, A[2] = 5, A[3] = 2, A[4] = -4, A[5] = 3, A[6]=0

3 is an equilibrium index, because:
A[0] + A[1] + A[2] = A[4] + A[5] + A[6]

6 is also an equilibrium index, because sum of zero elements is zero, i.e., A[0] + A[1] + A[2] + A[3] + A[4] + A[5]=0

7 is not an equilibrium index, because it is not a valid index of array A.
*/

#include<iostream>
using namespace std;
int equilibrium(int arr[], int n)
{
	int sum = 0;
	int left_sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	for (int i = 0; i < n; i++)
	{
		sum = sum - arr[i];
		if (sum == left_sum)
			return i;
		left_sum += arr[i];
	}
	return -1;
}
int main()
{
	int arr[] = { -7, 1, 5, 2, -4, 3, 0 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	cout << "First equilibrium index is : " << equilibrium(arr, arr_size);
    return 0;
}

