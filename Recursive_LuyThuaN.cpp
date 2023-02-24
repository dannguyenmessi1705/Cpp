#include <bits/stdc++.h>
using namespace std;
long long Power(int x, int n)
{
    if (n == 1)
    {
        return x;
    }
    if (n == 0)
    {
        return 1;
    }
    return x * Power(x, n - 1);
}
int main()
{
    int x, n;
    cin >> x >> n;
    cout << Power(x, n);
}