#include <bits/stdc++.h>
#define ll long long
using namespace std;
// ham nay la ham tinh giai thua
ll tinh(ll n)
{
    if (n == 0)
        return 1;
    return n * tinh(n - 1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n + 1], b[n + 1], kta[n + 1] = {0}, ktb[n + 1] = {0}, posta = 0, postb = 0;
        for (int i = 1; i <= n; i++)
        {
            int x = 0;
            cin >> a[i];
            kta[a[i]]++;
            for (int j = 1; j < a[i]; j++)
            {
                if (kta[j] == 0)
                {
                    x++;
                }
            }
            posta += x * tinh(n - i);
        }
        for (int i = 1; i <= n; i++)
        {
            int y = 0;
            cin >> b[i];
            ktb[b[i]]++;
            for (int j = 1; j < b[i]; j++)
            {
                if (ktb[j] == 0)
                {
                    y++;
                }
            }
            postb += y * tinh(n - i);
        }
        cout << abs(postb - posta) << endl;
    }
}