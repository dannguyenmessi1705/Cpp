#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, input;
        cin >> n;
        vector<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> input;
            s.push_back(input);
        }
        if (next_permutation(s.begin(), s.end()))
        {
            for (int i : s)
            {
                cout << i << " ";
            }
        }
        else
        {
            sort(s.begin(), s.end());
            for (int i : s)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}