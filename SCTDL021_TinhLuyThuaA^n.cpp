#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;
ll Power(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        n /= 2;
    }
    return res;
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        ll a, n;
        cin >> a >> n;
        cout << Power(a, n) << endl;
    }
}