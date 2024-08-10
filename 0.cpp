#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main()
{
    ll n, price = 1000, sum = 0;
    cin >> n;
    ll week = n / 7, day = n % 7;
    while (week--)
    {
        sum += price * 7;
        price += 1000;
    }
    sum += price * day;
    string s = to_string(sum);
    ll len = s.length();
    vector<char> v;
    for (int i = len - 1; i >= 0; i--)
    {
        if ((len - i - 1) % 3 == 0 && (len - i - 1) != 0)
            v.push_back('.');
        v.push_back(s[i]);
    }
    reverse(v.begin(), v.end());
    v.push_back('v');
    v.push_back('n');
    v.push_back('d');
    for (auto i : v)
        cout << i;
}