#include <bits/stdc++.h>
using namespace std;
long long BinPow(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    long long y = BinPow(x, n / 2);
    if (n & 1)
    {
        return y * y * x;
    }
    else
    {
        return y * y;
    }
}
int main()
{
    int x, n;
    cin >> x >> n;
    cout << BinPow(x, n);
}