#include<iostream>
using namespace std;

#define INF -999999
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
void knapSack(int val[], int wt[], int W, int n)
{
	int *T = new int[W + 1]; // to store maximum values for W=0,1,2,3.... W 
	int *Track = new int[W + 1]; // to keep track of items which give maximum
	for (int i = 0; i <= W; i++)
	{
		T[i] = INF;
		Track[i] = -1;
	}
	T[0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if (wt[i] <= j)  // if weight of current item (i) is less than or equal to current total weight ie for W=j , if it is more it will not contirbute
			{
				if (T[j - wt[i]] != INF)
				{
					T[j] = max(T[j], val[i] + T[j - wt[i]]);    // maximum of value obtained by including the item for W=j or by not including the item.
					if (T[j] == val[i] + T[j - wt[i]])
					{
						Track[j] = i; // update the value for traking the item
					}
				}
			}
		}
	}
	cout << "maximum value is : " << T[W] << "\n";
	cout << "items are : \n";
	int i = W;
	while (Track[i] != -1)
	{
		cout << wt[Track[i]] << " ";
		i = i - wt[Track[i]];
	}
}
int main()
{
	int W = 100;
	int val[] = { 10, 30, 20 };
	int wt[] = { 5, 10, 15 };
	int n = sizeof(val) / sizeof(val[0]);
	knapSack(val, wt, W, n);
	return 0;
}