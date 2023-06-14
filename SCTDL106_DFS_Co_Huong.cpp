#include <bits/stdc++.h>
using namespace std;
bool visted[10001];
set<int> adj[10001]; // Khoi tao danh sach ke
void DFS(int V)
{
    cout << V << " ";
    visted[V] = true;
    for (int U : adj[V])
    {
        if (!visted[U])
            DFS(U);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while (test--)
    {
        int n, m, start;
        cin >> n >> m >> start;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].insert(y);
        }
        memset(visted, false, sizeof visted);
        DFS(start);
        cout << endl;
    }
}