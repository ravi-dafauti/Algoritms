/*
Markov takes out his Snakes and Ladders game, stares at the board and wonders: "If I can always roll the die to whatever number I want, what would be the least number of rolls to reach the destination?"

Rules The game is played with a cubic die of  faces numbered  to .

Starting from square , land on square  with the exact roll of the die. If moving the number rolled would place the player beyond square , no move is made.

If a player lands at the base of a ladder, the player must climb the ladder. Ladders go up only.

If a player lands at the mouth of a snake, the player must go down the snake and come out through the tail. Snakes go down only.

Input Format

The first line contains the number of tests, .

For each testcase: 
- The first line contains , the number of ladders. 
- Each of the next  lines contains two space-separated integers, the start and end of a ladder. 
- The next line contains the integer , the number of snakes. 
- Each of the next  lines contains two space-separated integers, the start and end of a snake.

Constraints

 

The board is always  with squares numbered  to . 
Neither square  nor square  will be the starting point of a ladder or snake. 
A square will have at most one endpoint from either a snake or a ladder.

Output Format

For each of the t test cases, print the least number of rolls to move from start to finish on a separate line. If there is no solution, print -1.
*/
#include <iostream>
#include<vector>
#include<queue>


using namespace std;

struct Node {
	int v;
	int dis;
};
// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {

	queue<Node *> q;
	Node *s = new Node();
	s->v = 1;
	s->dis = 0;
	q.push(s);
	int arr[101];
	int vis[101];
	for (int i = 1; i <= 100; i++)
	{
		arr[i] = -1;
		vis[i] = 0;
	}
	for (int i = 0; i < ladders.size(); i++)
	{
		arr[ladders[i][0]] = ladders[i][1];
	}
	for (int i = 0; i < snakes.size(); i++)
		arr[snakes[i][0]] = snakes[i][1];
	Node *t;
	int flag = 0;
	while (!q.empty())
	{
		t = q.front();
		q.pop();
		if (t->v == 100)
		{
			flag = 1;
			break;
		}
		for (int i = 1; i <= 6 && t->v + i <= 100; i++)
		{

			if (vis[t->v + i] == 0)
			{
				vis[t->v + i] = 1;
				Node *tt = new Node;
				if (arr[t->v + i] == -1)
				{
					tt->v = t->v + i;
					tt->dis = t->dis + 1;
				}
				else
				{
					tt->v = arr[t->v + i];
					tt->dis = t->dis + 1;
				}
				q.push(tt);
			}

		}
	}
	if (flag = 0)
		return -1;
	return t->dis;
}

int main()
{

	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		int n;
		cin >> n;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		vector<vector<int>> ladders(n);
		for (int i = 0; i < n; i++) {
			ladders[i].resize(2);

			for (int j = 0; j < 2; j++) {
				cin >> ladders[i][j];
			}

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		int m;
		cin >> m;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		vector<vector<int>> snakes(m);
		for (int i = 0; i < m; i++) {
			snakes[i].resize(2);

			for (int j = 0; j < 2; j++) {
				cin >> snakes[i][j];
			}

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		int result = quickestWayUp(ladders, snakes);
	}

	return 0;
}
