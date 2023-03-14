#include <bits/stdc++.h>
using namespace std;
void DecToBin(int n, string &s)
{
    if (n <= 1)
        s += (char)(n + '0');
    else
    {

        DecToBin(n / 2, s);

        if (n % 2)
            s += '1';

        else
            s += '0';
    }
}

int main()
{
    int n;
    cin >> n;
    string s = "";
    DecToBin(n, s);
    cout << s;
}
