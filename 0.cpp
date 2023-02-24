#include <bits/stdc++.h>
using namespace std;
bool snt(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return n > 1;
}
bool dx(int a[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] != a[n - i - 1])
            return false;
    }
    return true;
}
void in(int a[], int a_check_dx[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a_check_dx[i] = a[i];
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    int a_check_dx[n];
    in(a, a_check_dx, n);
    int mi = INT_MAX, mx = INT_MIN, vitrimin = 0, vitrimax = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mx)
            mx = max(a[i], mx);
        if (a[i] < mi)
            mi = min(a[i], mi);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == mx)
        {
            vitrimax = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == mi)
        {
            vitrimin = i;
            break;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (snt(a[i]))
            cnt++;
    }
    cout << mx << " " << vitrimax << endl;
    cout << mi << " " << vitrimin << endl;
    cout << cnt << endl;
    sort(a, a + n, greater<int>());
    long long min1 = a[0] * a[1];
    sort(a, a + n);
    long long min2 = a[0] * a[1];
    cout << max(min1, min2) << endl;
    if (dx(a_check_dx, n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    long long res = 1;
    for (int i = 0; i < n; i++)
    {
        res *= a[i];
        res %= (int)1e9 + 7;
    }
    cout << res << endl;
}