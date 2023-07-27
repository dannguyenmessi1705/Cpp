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
}