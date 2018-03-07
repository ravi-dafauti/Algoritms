/*Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.

Input :   0 1 1 0
          1 1 1 1
          1 1 1 1
          1 1 0 0

Output :  1 1 1 1
          1 1 1 1
	  
Step 1: Find maximum area for row[0]
Step 2:
    for each row in 1 to N - 1
        for each column in that row
            if A[row][column] == 1
              update A[row][column] with
                A[row][column] += A[row - 1][column]
    find area for that row
    and update maximum area so far */

#include<iostream>
#include<stack>
using namespace std;

#define R 4
#define C 4

int maxAreaInHisto(int arr[], int n)
{
	stack<int> mStack;
	int i = 0;
	int max_area = 0;
	int curr_area = 0;
	while (i<n)
	{
		if (mStack.empty() || arr[i] >= arr[mStack.top()])
		{
			mStack.push(i);
			i++;
		}
		else
		{
			int t = mStack.top();
			mStack.pop();
			if (mStack.empty())
				curr_area = i*arr[t];
			else
				curr_area = (i - mStack.top() - 1)*arr[t];
			if (max_area < curr_area)
				max_area = curr_area;
		}
	}
	while (!mStack.empty())
	{
		int t = mStack.top();
		mStack.pop();
		if (mStack.empty())
			curr_area = i*arr[t];
		else
			curr_area = (i - mStack.top() - 1)*arr[t];
		if (max_area < curr_area)
			max_area = curr_area;
	}
	return max_area;
}
int maxRectangle(int A[][C])
{
	int *temp_arr = new int[C];
	int max = 0;
	int currmax = 0;
	for (int i = 0; i < R; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < C; j++)
				temp_arr[j] = A[i][j];
			currmax = maxAreaInHisto(temp_arr, C);
		}
		else
		{
			for (int j = 0; j < C; j++)
			{
				if (A[i][j] == 0)
					temp_arr[j] = 0;
				else
					temp_arr[j] += A[i][j];
				currmax = maxAreaInHisto(temp_arr, C);
			}
		}
		if (max < currmax)
			max = currmax;
	}
	return max;
}
int main()
{
	int A[][C] = { { 0, 1, 1, 0 },
	{ 1, 1, 1, 1 },
	{ 1, 1, 1, 1 },
	{ 1, 1, 0, 0 },
	};

	int arr[] = { 2,3,3,2 };
	cout << "Area of maximum rectangle is "
		<< maxRectangle(A);

	return 0;
}
