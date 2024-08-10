<<<<<<< HEAD
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
=======
// Tìm độ dài của xâu ký tự cuối cùng trong chuỗi bao gồm dấu cách
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int i = s.length() - 1;
    while (!((s[i] <= 'Z' && s[i] >= 'A') || (s[i] <= 'z' && s[i] >= 'a') || (s[i] <= '9' && s[i] >= '0')))
    {
        i--;
    }
    int j = i;
    while (s[j] != ' ' && j >= 0)
    {
        j--;
    }
    cout << i - j << endl;
>>>>>>> 025ac0a2cb48fb536e3826fdb08321f5f75f6846
}