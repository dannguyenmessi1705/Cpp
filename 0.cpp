// du thua dau ngoac
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string s;
        cin >> s;
        vector<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] != ')')
            {
                st.push_back(s[i]);
            }
            else
            {
                bool ok = 1;
                while (st.back() != '(')
                {
                    if (st.back() == '+' || st.back() == '-' || st.back() == '*' || st.back() == '/')
                    {
                        ok = 0;
                    }
                    st.pop_back();
                }
                if (ok)
                {
                    cout << "YES" << endl;
                    return 0;
                }
                st.pop_back();
            }
        }
        cout << "NO" << endl;
    }
}