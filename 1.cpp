// CPP program to implement traveling salesman
// problem using naive approach.
#include <bits/stdc++.h>
using namespace std;
#define V 5

// implementation of traveling Salesman Problem
int travllingSalesmanProblem(int graph[][V], int s)
{
	// store all vertex apart from source vertex
	vector<int> vertex;
	for (int i = 0; i < V; i++)
		if (i != s)
			vertex.push_back(i);

	// store minimum weight Hamiltonian Cycle.
	int min_path = INT_MAX;
	do {

		// store current Path weight(cost)
		int current_pathweight = 0;

		// compute current path weight
		int k = s;
		for (int i = 0; i < vertex.size(); i++) {
			current_pathweight += graph[k][vertex[i]];
			k = vertex[i];
		}
		current_pathweight += graph[k][s];

		// update minimum
		min_path = min(min_path, current_pathweight);

	} while (
		next_permutation(vertex.begin(), vertex.end()));

	return min_path;
}

// Driver Code
int main()
{
	// matrix representation of graph
	int graph[][V] = { { 0, 8 , 5, 22, 11 },
					{ 4, 0, 9, 17, 27 },
					{ 15, 7, 0, 12, 35 },
					{ 5, 27, 17, 0, 29 },
                    {23, 21, 10, 7, 0} };
	int s = 0;
	cout << travllingSalesmanProblem(graph, s) << endl;
	return 0;
}
