#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        vector<int> s;
        int n;
        cin >> n;
        for (int i = n; i > 0; i--)
        {
            s.push_back(i);
        }
        do
        {
            for (int i : s)
            {
                cout << i;
            }
            cout << " ";
        } while (prev_permutation(s.begin(), s.end()));
        cout << endl;
    }
}