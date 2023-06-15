#include <bits/stdc++.h>
using namespace std;
int checkRedundancy(string s)
{
    // code here
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            bool what = true;
            while (!st.empty() && st.top() != '(')
            {
                st.pop();
                what = false;
            }
            st.pop();
            if (what)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int test;
    cin >> test;
    cin.ignore();
    while (test--)
    {
        string s;
        getline(cin, s);
        if (checkRedundancy(s))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}