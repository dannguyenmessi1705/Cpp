#include <bits/stdc++.h>
using namespace std;
double Pow_n(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return x * Pow_n(x, n - 1);
}
double Square_Root(int n, int m, double x)
{
    double xn = ((m - 1) * x) / m + n / (m * pow(x, m - 1));
    if (abs(xn - x) < 0.0001)
    {
        return xn;
    }
    return Square_Root(n, m, xn);
}
double Square_nth(int n, int m)
{
    double x0 = n / m;
    return Square_Root(n, m, x0);
}
int main()
{
    int x, m, n;
    cin >> x >> m >> n;
    cout << Pow_n(Square_nth(x, m), n);
}