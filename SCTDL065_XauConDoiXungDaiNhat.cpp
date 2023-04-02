#include <bits/stdc++.h>
using namespace std;
// Tim do dai max cua cac xau le doi xung
// VD abcba (len=5 la le) => duyet tu diem giua c roi chay ve 2 ben 
int MaxLe(string s)
{
    int len = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int left = i, right = i;
        while (~left && right < s.size())
        {
            if (s[left] == s[right])
            {
                len = max(len, right - left + 1);
                left--;
                right++;
            }
            else
                break;
        }
    }
    return len;
}
// Tim do dai max cua cac xau chan doi xung
// VD abba (len=4 chan) => duyet tu diem giua (3/2 = s[1]), chon left chinh bang 1, right = left+1
// Tiep tuc tinh tien ve 2 phia
int MaxChan(string s)
{
    int len = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int left = i, right = i + 1;
        while (~left && right < s.size())
        {
            if (s[left] == s[right])
            {
                len = max(len, right - left + 1);
                left--;
                right++;
            }
            else
                break;
        }
    }
    return len;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while (test--)
    {
        string s;
        cin >> s;
        cout << max(MaxChan(s), MaxLe(s)) << endl;
    }
}