#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while (test--)
    {
        vector<int> adj[10001]; // Khoi tao danh sach ke
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        for (int i = 1; i <= n; i++)
        {
            cout << i << ": ";
            for (int x : adj[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
}