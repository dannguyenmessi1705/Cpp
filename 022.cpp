#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f[100005], n;
void fibo()
{
    f[0] = 1;
    f[1] = 2;
    for (int i = 2; i <= 25; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
}
ll solved(ll n, ll CurrNum = 0, ll CurrSum = 0)
{
    ll p = f[CurrNum];
    ll res = 0;
    while (CurrSum + p < n)
    {
        res += solved(n, CurrNum + 1, CurrSum + p);
        CurrNum++;
        p = f[CurrNum];
    }

    if (CurrSum + p == n)
    {
        res++;
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    fibo();
    while (t--)
    {
        cin >> n;
        cout << solved(n) << endl;
    }
}