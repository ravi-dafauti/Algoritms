#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
int fun(int arr[], int index)
{
	if (index == 0)
		return -1;
	if (fun(arr, index - 1) == -1)
	{
		if (arr[index] >= arr[index - 1])
			return -1;
		else
		{
			for (int i = 0; i < index; i++)
			{
				if (arr[i] > arr[index])
				{
					int temp = arr[i];
					arr[i] = arr[index];
					arr[index] = temp;
					break;
				}
			}
			sort(arr, arr + index, greater<int>());
			return 1;
		}
	}
	return 1;
}
int main()
{
	int arr[100001];
	int n;
	int i;
	int t;
	cin >> t;
	while (t)
	{
		cin >> n;
		i = 0;
		while (n)
		{
			arr[i] = n % 10;
			n = n / 10;
			i++;
		}
		if (fun(arr, i - 1) != -1)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				cout << arr[j];
			}
		}
		else
			cout << "not possible";
		cout << "\n";
		t--;
	}
    return 0;
}

