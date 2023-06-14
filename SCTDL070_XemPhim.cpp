#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int s, n;
        cin >> s >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= s; j++)
                if (a[i] <= j)
                    dp[i][j] = max(dp[i - 1][j - a[i]] + a[i], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
        cout << dp[n][s] << endl;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = 0;
    }
    return 0;
}
