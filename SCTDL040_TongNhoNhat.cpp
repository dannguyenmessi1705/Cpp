#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void In(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int a[30], n;
        cin >> n;
        In(a, n);
        sort(a, a + n);
        ll sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i += 2)
        {
            sum1 = sum1 * 10 + a[i];
        }
        for (int i = 1; i < n; i += 2)
        {
            sum2 = sum2 * 10 + a[i];
        }
        cout << sum1 + sum2 << endl;
    }
}