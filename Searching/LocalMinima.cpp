/* find the local minima of array
3,2,1,4,5,6
local minima is 1
*/
#include<iostream>
using namespace std;
int localMinima(int arr[], int low, int high)
{
	if (low > high)
		return -1;
	if (low == high)
		return low;
	if (low + 1 == high)
	{
		if (arr[low] < arr[high])
			return low;
		else
			return high;
	}
	int mid = (low + high) / 2;
	if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1])
		return mid;
	else if (arr[mid]<arr[mid - 1] && arr[mid]>arr[mid + 1])
		return localMinima(arr, mid + 1, high);
	else if (arr[mid]>arr[mid - 1] && arr[mid] < arr[mid + 1])
		return localMinima(arr, low, mid - 1);
	return -1;
}
int main()
{
	int arr[] = { 6,5,4,3,2,1,7,8,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int minima = localMinima(arr, 0, size - 1);
	if (minima != -1)
		cout << "minima is : " << arr[minima];
	return 0;
}