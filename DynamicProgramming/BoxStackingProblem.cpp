/*
You are given a set of n types of rectangular 3-D boxes, where the i^th box has height h(i), width w(i) and depth d(i) (all real numbers). 
You want to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base. 
It is also allowable to use multiple instances of the same type of box.
*/
#include<iostream>
using namespace std;
struct Box
{
	int h, w, l;
};
int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
void sort(Box arr[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int max = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[max].l*arr[max].w < arr[j].l*arr[j].w)
			{
				max = j;
			}
		}
		if (max != i)
		{
			Box temp = arr[max];
			arr[max] = arr[i];
			arr[i] = temp;
		}
	}
}
int maxStackHeight(Box arr[], int n)
{
	Box *temp = new Box[n * 3];
	int j = 0;
	//save all rotations of box in temp array
	for (int i = 0; i < n; i++)
	{
		temp[j] = arr[i];
		j++;
		temp[j].h = arr[i].l;
		temp[j].l = max(arr[i].h, arr[i].w);
		temp[j].w = min(arr[i].h, arr[i].w);
		j++;
		temp[j].h = arr[i].w;
		temp[j].l = max(arr[i].h, arr[i].l);
		temp[j].w = min(arr[i].h, arr[i].l);
		j++;
	}
	//sort temp array on basis of base area in descending order
	sort(temp, n * 3);
	// now apply LIS
	int *dp = new int[n * 3];
	for (int i = 0; i < n * 3; i++)
	{
		dp[i] = temp[i].h;
	}
	int max_height = 0;
	for (int i = 1; i < n * 3; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (temp[i].l < temp[j].l && temp[i].w < temp[j].w) // if strickly smaller then it can come on top
			{
				dp[i] = max(dp[i], dp[j] + temp[i].h);
				if (dp[i] > max_height)
				{
					max_height = dp[i];
				}
			}
		}
	}
	return max_height;
}
int main()
{
	Box arr[] = { { 4, 6, 7 },{ 1, 2, 3 },{ 4, 5, 6 },{ 10, 12, 32 } };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "The maximum possible height of stack is : " << maxStackHeight(arr, n);

	return 0;
}