#include<iostream>
#include<vector>

using namespace std;

void recur(vector<int> &arr, vector<vector<int>> &subset, vector<int> &temp, int index)
{
	if (index == arr.size())
		return;
	for (int i = index; i < arr.size(); i++)
	{
		temp.push_back(arr[i]);
		subset.push_back(temp);
		recur(arr, subset, temp, i + 1);
		temp.pop_back();
	}
}
vector<vector<int>> subsets(vector<int> &arr)
{
	vector<vector<int>> subset;
	vector<int> temp;
	subset.push_back(temp);
	recur(arr, subset, temp, 0);
	return subset;
}
int main()
{
	vector<int> arr = { 1, 2, 3 };
	vector < vector < int >> subset = subsets(arr);
	for (int i = 0; i < subset.size(); i++)
	{
		for (int j = 0; j < subset[i].size(); j++)
		{
			cout << subset[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}