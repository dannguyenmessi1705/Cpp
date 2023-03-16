#include <bits/stdc++.h>
using namespace std;
struct data
{
    long long x[10][10];
};
int n;
const int MOD = 1e9 + 7;
struct data operator*(struct data a, struct data b)
{
    struct data M;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            M.x[i][j] = 0;
            for (int k = 0; k < n; k++)
                M.x[i][j] = (M.x[i][j] + (a.x[i][k] * b.x[k][j]) % MOD) % MOD;
        }
    }
    return M;
};
struct data poww(struct data a, long long k)
{
    if (k == 1)
        return a;
    if (k % 2 == 1)
        return a * poww(a, k - 1);
    struct data M = poww(a, k / 2);
    return M * M;
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        long long k;
        cin >> n >> k;
        struct data a;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a.x[i][j];
        a = poww(a, k);
        unsigned long long ans = 0;
        for (int i = 0; i < n; i++)
        {

            ans += a.x[n - i - 1][i];
            ans %= MOD;
            // cout << a.x[i][j] << " ";
        }
        cout << ans << endl;
    }
}