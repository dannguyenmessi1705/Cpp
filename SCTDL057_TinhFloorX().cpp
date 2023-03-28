#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void In(ll *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
int FloorX(ll *a, int n, int X)
{
    int pos = -2;
    int left = 0, right = n - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] > X)
        {
            right = mid;
        }
        else
        {
            pos = mid;
            left = mid + 1;
        }
    }
    return pos;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while (test--)
    {
        int n, X;
        cin >> n >> X;
        ll a[n];
        In(a, n);
        sort(a, a + n);
        cout << FloorX(a, n, X) + 1 << endl;
    }
}