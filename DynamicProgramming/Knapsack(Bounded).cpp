#include<iostream>
using namespace std;

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
void knapSack(int val[], int wt[], int W, int n)
{
	//create array of T[n][W]
	int **T = (int **)malloc(sizeof(int)*(n + 1));
	for (int i = 0; i <= n; i++)
		T[i] = (int*)malloc(sizeof(int)*(W + 1));

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if (i == 0 || j == 0)   // no contribution 
				T[i][j] = 0;
			else
			{
				if (j < wt[i-1])       // if weight of current item is more than that of current total weight ignore the element
					T[i][j] = T[i - 1][j];
				else
					T[i][j] = max(T[i - 1][j], T[i - 1][j - wt[i-1]] + val[i-1]);  /* we take maximum of T[i - 1][j] (ie excluding item i-1) and  T[i - 1][j - wt[i-1]] + val[i-1] (i.e. including item i-1)*/
			}                                                                      /*T[i - 1][j - wt[i-1]] + val[i-1] == value of the item plus maximum we can get for remaining total weight after including that item*/
		}
	}
	int i = n;
	int j = W;
	cout << "maximum value is : " << T[n][W] << "\n";
	cout << "weights are : \n";
	//track items
	while (T[i][j] != 0)
	{
		if (T[i][j] != T[i - 1][j])    // weight i-1 was included so print it and move to point where we get maximum for remaining total weight
		{
			cout << wt[i - 1] << " ";
			j = j - wt[i - 1];
			i = i - 1;
		}
		else                         // i-1 item was not included so move to previous item and check again
		{
			i = i - 1;
		}
	}
}
int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int  W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	knapSack(val, wt, W, n);
	return 0;
}