#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while (test--)
    {
        int Na, Nb, A;
        cin >> Na >> Nb;
        int dp[MAX]{};
        for (int i = 0; i < Na + Nb; i++)
        {
            cin >> A;
            dp[A]++;
        }
        for (int i = 0; i < MAX; i++)
            if (dp[i] > 0)
                cout << i << " ";
        cout << endl;
        for (int i = 0; i < MAX; i++)
            if (dp[i] > 1)
                cout << i << " ";
        cout << endl;
    }
}