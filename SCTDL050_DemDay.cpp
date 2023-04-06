#include <bits/stdc++.h>
using namespace std;

int mod = 123456789;
typedef long long ll;

inline ll calc(ll n)
{
    if (n == 1)
        return 1;
    long long x = calc(n >> 1) % mod;
    if (n & 1)
        return (((x * x % mod) << 2) % mod) % mod;
    return (((x * x % mod) << 1) % mod) % mod;
}

int main()
{
    int t = 1;
    ll n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << calc(n) << endl;
    }
    return 0;
}