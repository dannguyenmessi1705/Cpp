#include <iostream>
using namespace std;

const int MAX_N = 505;
const int MAX_K = 2000005;

int K, N;
int Value[MAX_N], Weight[MAX_N];
int MaxCost[2][MAX_K];
// MAX[1][j] là giá tr? l?n nh?t thu du?c
// v?i vi?c ch?n t? d? v?t t? 1 d?n i và
// kh?i lu?ng không vu?t quá j

// MAX[0][j] là giá tr? cu tru?c dó.
// Và ngu?c l?i

int Max(int a, int b)
{
	if(a > b) return a;
	return b;
}

int main()
{
	int T, test_case;
	ios::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	cin >> K >> N;
	for(int i = 1; i <= N; i++)
	    cin >> Value[i] >> Weight[i];

	// Tru?ng h?p co s?
	for(int j = 0; j <= K; j++)
		MaxCost[0][j] = 0;

	for(int i = 0; i < 2; i++)
		MaxCost[i][0] = 0;

	int before = 0, current = 1;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= K; j++)
		{
			// Không ch?n v?t i
			MaxCost[current][j] = MaxCost[before][j];
			int a = MaxCost[current][j];

			// Ch?n v?t i
			if(Weight[i] <= j) 
				MaxCost[current][j] = Max(MaxCost[current][j], MaxCost[before][j - Weight[i]] + Value[i]);
			int b = MaxCost[current][j];
		}

		// Ð?i current và before cho nhau.
		current = 1 - current;
		before  = 1 - before;
	}
	// N ch?n thì k?t qu? là MaxCost[0][K]
	// N l? thì k?t qu? là MaxCost[1][K]
	cout << MaxCost[N % 2][K] << endl;

	return 0;//Your program should return 0 on normal termination.
}