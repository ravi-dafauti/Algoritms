/*
Given an array of integers A and a sum B, find all unique combinations in A where the sum is equal to B. The same repeated number may be chosen from A unlimited number of times.
Note:
All numbers will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
If there is no combination possible the print "Empty" (without qoutes).
Example,
Given A = 2,4,6,8 and B(sum) = 8,
A solution set is:

[2, 2, 2, 2]
[2, 2, 4]
[2, 6]
[4, 4]
[8]

Input:
First is T , no of test cases. 1<=T<=500
Every test case has three lines.
First line is N, size of array. 1<=N<=12
Second line contains N space seperated integers(x). 1<=x<=9.
Third line is the sum B. 1<=B<=30.
 
Output:
One line per test case, every subset enclosed in () and in every set intergers should be space seperated.(See example)

Example:
Input:
3
4
7 2 6 5
16
11
6 5 7 1 8 2 9 9 7 7 9
6
4
5 2 2 6
3

Output:
(2 2 2 2 2 2 2 2)(2 2 2 2 2 6)(2 2 2 5 5)(2 2 5 7)(2 2 6 6)(2 7 7)(5 5 6)
(1 1 1 1 1 1)(1 1 1 1 2)(1 1 2 2)(1 5)(2 2 2)(6)
Empty
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int flag=0;
void print(int arr[], int n, vector<int> &v, int &cs, int sum,int index)
{
	if (cs == sum)
	{
	    flag=1;
		vector<int>::iterator it;
		cout<<"(";
		for (it = v.begin(); it != v.end(); it++)
		{
		    if(it+ 1==v.end())
		    cout<<*it;
		    else
		    cout << *it << " ";
		}
			cout<<")";
		return;
	}
	for (int i = index; i < n && cs + arr[i] <= sum; i++)
	{
		v.push_back(arr[i]);
		cs = cs + arr[i];
		print(arr, n, v, cs, sum, i);
		cs = cs - arr[i];
		v.pop_back();
	}
}
void removeDuplicates(int arr[],int &n)
{
    int index=-1;
    for(int i=0;i<n;i++)
    {
        if(index==-1 || arr[index]!=arr[i])
        {
            index++;
            arr[index]=arr[i];
        }
    }
    n=index+1;
}
int main()
{
    int t;
    cin>>t;
    int n;
    int arr[13];
    int s;
    int cs;
    while(t)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        cin>>arr[i];
        sort(arr,arr+n);
        removeDuplicates(arr,n);
        cin>>s;
        vector<int> v;
        cs=0;
        flag=0;
	    print(arr, n, v, cs, s, 0);
	    if(flag==0)
	    {
	        cout<<"Empty";
	    }
	    cout<<"\n";
        t--;
    }
	
    return 0;
}
