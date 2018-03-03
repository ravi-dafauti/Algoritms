/*There are M job applicants and N jobs. Each applicant has a subset of jobs that he/she is interested in. 
Each job opening can only accept one applicant and a job applicant can be appointed for only one job. 
Find an assignment of jobs to applicants in such that as many applicants as possible get jobs.

this can be represented by bipartite graph.
and then maximum matching is the answer. ie ghe maximum candidates that can get job.
(NOTE:: A matching in a Bipartite Graph is a set of the edges chosen in such a way that no two edges share an endpoint. A maximum matching is a matching of maximum size (maximum number of edges). 
In a maximum matching, if any edge is added to it, it is no longer a matching. There can be more than one maximum matchings for a given Bipartite Graph.)
*/
#include<iostream>
using namespace std;

#define M 6
#define N 6

bool MBM_Util(int graph[M][N], int assigned[], int seen[], int applicant)
{
	for (int i = 0; i < N; i++)   // check for all jobs until we can assign one
	{
		if (graph[applicant][i] == 1 && seen[i] == 0)  // if the candidate has applied for the job and the job is not seen yet
		{
			seen[i] = 1;   //mark as seen
			if (assigned[i] == -1 || MBM_Util(graph, assigned, seen, assigned[i]))   // if the job is not assinged yet or the job can be assigned after reassigning the job for the allocated candidate then assign the job and return true
			{
				assigned[i] = applicant;
				return true;
			}
		}
	}
	return false;  // if no jobs can be assigned then return false
}
int MBM(int graph[M][N])
{
	int max_count = 0;
	int *assigned = new int[N];
	int *seen = new int[N];
	for (int i = 0; i < N; i++)
	{
		assigned[i] = -1;
		seen[i] = 0;
	}
	for (int i = 0; i < M; i++)
	{
		if (MBM_Util(graph, assigned, seen, i)) // if we can assign job to a candidate then increase count
			max_count++;
	}
	return max_count;
}

int main()
{
	int bpGraph[M][N] = { { 0, 1, 1, 0, 0, 0 },
	{ 1, 0, 0, 1, 0, 0 },
	{ 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1 }
	};

	cout << "Maximum number of applicants that can get job is "
		<< MBM(bpGraph);
	return 0;
}