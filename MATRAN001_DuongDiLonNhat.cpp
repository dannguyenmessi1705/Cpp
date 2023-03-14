#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;

int test, m, n, a[1005][1005], dp[1005][1005];
int main()
{
    cin >> test;
    while (test--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        for (int i = 1; i <= m; i++)
            dp[1][i] = a[1][i];
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = -1;
            dp[i][m + 1] = -1;
        }
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= m; j++)
                dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i - 1][j + 1])) + a[i][j];
        int maxRoute = 0;
        for (int i = 1; i <= m; i++)
            maxRoute = max(maxRoute, dp[n][i]);
        cout << maxRoute << endl;
    }
}