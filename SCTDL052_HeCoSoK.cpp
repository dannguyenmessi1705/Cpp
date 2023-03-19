#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ConvertToDec(string a, int K)
{
    ll dec = 0;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        if (a[i] <= '9' && a[i] >= '0')
            dec += (int)(a[i] - '0') * pow(K, a.length() - i - 1);
        else
        {
            dec += (int)(a[i] - 'A' + 10) * pow(K, a.length() - i - 1);
        }
    }
    return dec;
}
string ConvertToK(ll a, int K)
{
    string inK = "";
    while (a > 0)
    {
        int num = a % K;
        if (num < 10)
            inK += (char)(num + '0');
        else
        {
            inK += (char)(num - 10 + 'A');
        }
        a /= K;
    }
    reverse(inK.begin(), inK.end());
    return inK;
}
string SUM(string a, string b, int K)
{
    ll DecA = ConvertToDec(a, K);
    ll DecB = ConvertToDec(b, K);
    ll DecSum = DecA + DecB;
    return ConvertToK(DecSum, K);
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string a, b;
        int K;
        cin >> K >> a >> b;
        cout << SUM(a, b, K) << endl;
    }
}