#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n;
int Count(ll n)
{
    int cnt = 0;
    while (n >= 5)
    {
        n /= 5;
        cnt++;
    }
    return cnt;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll ans = 0;
        for (int i = 1; i <= Count(n); ++i)
        {
            ans += n / (pow(5, i));
        }
        cout << ans << endl;
    }
}
/*
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = 0;
        ll mu = 5;
        while (n/mu)
        {
            ans += n / mu;
            mu *= 5;
        }
        cout << ans << endl;
    }
}
*/