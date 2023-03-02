#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
void in(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> *(a + i);
    }
}
ll Max(int *a, int n)
{
    ll max = 0;
    for (int i = 0; i < n; i++)
    {
        max += ((a[i] % MOD) * (i % MOD)) % MOD;
    }
    return max;
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        int *a = new int[n];
        in(a, n);
        sort(a, a + n);
        cout << Max(a, n) << endl;
    }
}