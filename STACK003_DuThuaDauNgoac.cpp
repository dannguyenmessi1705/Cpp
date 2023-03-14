// C++ code to implement the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to check if the given character is an operator
// or not
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    }
    return false;
}

// Function to check if the given string contains redundant
// brackets or not
bool hasRedundantBrackets(string str)
{
    int n = str.length();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            count++;
        }
        else if (str[i] == ')')
        {
            if (count <= 1)
            {
                return true;
            }
            else
            {
                count--;
                while (i < n - 1 && isOperator(str[i + 1]))
                {
                    i += 2;
                }
            }
        }
        else if (isOperator(str[i]))
        {
            continue;
        }
    }

    return false;
}

// Driver code
int main()
{
    string str;
    getline(cin, str);

    if (hasRedundantBrackets(str))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
// This code is contributed by Veerendra_Singh_Rajpoot
