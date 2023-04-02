// Hau To ve Tien To
#include <bits/stdc++.h>
using namespace std;
#define IsToanTu s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    string s, tmp;
    while (test--)
    {
        cin >> s;
        stack<string> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (IsToanTu)
            {
                tmp = st.top();
                st.pop();
                tmp = st.top() + tmp;
                st.pop();
                tmp = s[i] + tmp;
                st.push(tmp);
            }
            else
                st.push(string(1, s[i]));
        }
        cout << st.top() << endl;
    }
}