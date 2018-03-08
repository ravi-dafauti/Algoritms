/*Given a 2D array, find the maximum sum subarray in it. 
For example, in the following 2D array, the maximum sum of subarray is 29.
{1, 2, -1, -4, -20},
{-8, -3, 4, 2, 1},
{3, 8, 10, 1, 3},
{-4, -1, 1, 7, -6}
*/
#include<iostream>
using namespace std;
#define ROW 4
#define COL 5
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
// returns maximum sum of subarray in the given array
int kadanes(int arr[], int *left, int *right, int n)
{
	int *dp = new int[n];
	for (int i = 0; i < n; i++)
		dp[i] = arr[i];
	int max_sum = arr[0];
	*left = *right = 0;
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i], dp[i - 1] + arr[i]);
		if (max_sum < dp[i])
		{
			max_sum = dp[i];
			if (dp[i] == dp[i - 1] + arr[i])
				*right = i;
			else
				*left = *right = i;
		}
	}
	return max_sum;
}
void findMaxSum(int arr[ROW][COL])
{
	int max_sum = -999999; //stores the maximum sum
	int maxleft; // stores the left index of max sum rectangle
	int maxright;  // stores the right index of max sum rectangle
	int maxtop;  // stores the top index of max sum rectangle
	int maxbottom;  // stores the bottom index of max sum rectangle
	int *temparr = new int[ROW];

	int L, R;
	int T, B;
	int curr_sum;
	for (L = 0; L < COL; L++)
	{
		for (int i = 0; i < ROW; i++)
			temparr[i] = 0;
		for (R = L; R < COL; R++)
		{
			for (int i = 0; i < ROW; i++)
				temparr[i] += arr[i][R];
			curr_sum = kadanes(temparr, &T, &B, ROW); // apply kadnes to this subrectangle
			if (curr_sum>max_sum)
			{
				max_sum = curr_sum;  //update maxsum and boundaries of subrectangle
				maxleft = L;
				maxright = R;
				maxtop = T;
				maxbottom = B;

			}
		}
	}
	cout << "top and left are : " << maxtop << " , " << maxleft << "\n";
	cout << "bottom and right are : " << maxbottom << " , " << maxright << "\n";
	cout << "maximum sum of sub rectangle is " << max_sum;
}
int main()
{
	int M[ROW][COL] = { { 1, 2, -1, -4, -20 },
	{ -8, -3, 4, 2, 1 },
	{ 3, 8, 10, 1, 3 },
	{ -4, -1, 1, 7, -6 }
	};

	findMaxSum(M);
	return 0;
}