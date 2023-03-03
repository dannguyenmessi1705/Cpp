#include <bits/stdc++.h>
using namespace std;
void Rev(string &s, int start, int end)
{
    if (start >= end)
        return;
    swap(s[start], s[end]);
    return Rev(s, start + 1, end - 1);
}
int main()
{
    string s;
    cin >> s;
    Rev(s, 0, s.length() - 1);
    cout << s;
}
