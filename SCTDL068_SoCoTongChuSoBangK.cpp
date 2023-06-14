/*Make it count*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll f[105][50005] = {};
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);

    for (int i = 1; i <= 9; i++)
        f[1][i] = 1;
    for (int i = 2; i <= 100; i++)
    {
        for (int j = 5000; j >= 0; j--)
        {
            for (int k = 0; k <= 9; k++)
            {
                if (j >= k)
                {
                    f[i][j] += f[i - 1][j - k];
                    f[i][j] %= MOD;
                }
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << f[n][k] << endl;
    }

    return 0;
}