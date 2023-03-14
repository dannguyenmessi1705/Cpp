#include <bits/stdc++.h>
using namespace std;

string hautoToTrungTo(string str)
{
    stack<string> st;

    for (int i = 0; i < str.size(); i++)
    {
        string temp = ""; // variable to store substring

        // traverse each character, nếu là toán tử or operand thì đưa vào stack
        if (str[i] >= 'a' && str[i] <= 'z')
            st.push(string(1, str[i]));
        else
        {
            // pop two recent elements from stack
            string op1 = st.top(), op2;
            st.pop();

            op2 = st.top();
            st.pop();

            temp += '(';
            temp += op2;
            temp += str[i];
            temp += op1;
            temp += ')';

            st.push(temp);
        }
    }

    return st.top(); // output expression
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string str;
        cin >> str;
        cout << hautoToTrungTo(str) << endl;
    }
}