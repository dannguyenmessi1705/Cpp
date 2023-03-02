#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> s;
    int n;
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        s.push_back(0);
    }
    // Next_Permutation
    cout << "Hoan vi ke tiep:\n";
    sort(s.begin(), s.end());
    do
    {
        for (int i : s)
        {
            cout << i << " ";
        }
        cout << endl;
    } while (next_permutation(s.begin(), s.end()));

    // Previous Permutation
    cout << "Hoan vi nguoc:\n";
    sort(s.begin(), s.end(), greater<int>());
    do
    {
        for (int i : s)
        {
            cout << i << " ";
        }
        cout << endl;
    } while (prev_permutation(s.begin(), s.end()));
}