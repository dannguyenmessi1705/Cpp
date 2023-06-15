// Sinh xau n bit
// 3 bit
// 000, 001, 010, 011, 100, 101, 111
#include <bits/stdc++.h>
using namespace std;
void Sinh(int n, int len, string s)
{
    if (len == n)
    {
        cout << s << endl;
        return;
    }
    Sinh(n, len + 1, s + "0");
    Sinh(n, len + 1, s + "1");
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    Sinh(n, 0, "");
}
