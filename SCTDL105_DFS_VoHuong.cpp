#include <bits/stdc++.h>
using namespace std;
bool visted[1001];
set<int> adj[1001]; // Khoi tao danh sach ke
void DFS(int V)
{
    cout << V << " ";
    visted[V] = true;
    // Duyet cac dinh ke voi V
    for (int U : adj[V])
    {
        if (!visted[U])
        { // Neu U chua duoc tham thi ta se tham U
            DFS(U);
        }
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
        // Nhap danh sach canh dong thoi chuyen ve danh sach ke
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].insert(y);
            adj[y].insert(x);
        }
        memset(visted, false, sizeof(visted));
        DFS(start);
        cout << endl;
    }
}