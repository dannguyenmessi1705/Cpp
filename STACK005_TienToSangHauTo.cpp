#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    getline(cin, s);
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            string tmp1 = st.top();
            st.pop();
            string tmp2 = st.top();
            st.pop();
            string tmp = tmp1 + tmp2 + s[i];
            st.push(tmp);
        }
        else
        {
            string tmp = "";
            tmp += s[i];
            st.push(tmp);
        }
    }
    cout << st.top() << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {

        solve();
    }
}