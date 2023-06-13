#include <bits/stdc++.h>
using namespace std;
bool visted[10001];
set<int> adj[10001];
int parent[10001]; // mang luu cac dinh cha cua dinh V
void DFS(int V)
{
    visted[V] = true;
    // Duyet cac dinh ke voi V
    for (int U : adj[V])
    {
        if (!visted[U])
        {                  // Neu U chua duoc tham thi ta se tham U
            parent[U] = V; // Them dinh V la dinh cha cua dinh U vao mang
            DFS(U);
        }
    }
}
void FindPath(int start, int end)
{
    memset(parent, 0, sizeof parent);
    memset(visted, false, sizeof visted);
    DFS(start);
    if (!visted[end])
    {
        cout << "Do thi khong lien thong, khong the tim duong di toi end";
    }
    else
    {
        // Truy vet nguoc lai tu dinh cuoi ve dinh dau
        vector<int> path;
        while (end != start)
        {                        // Kiem tra xem dinh cuoi da trung voi diem dau hay chua
            path.push_back(end); // Them duong di vao vector path
            end = parent[end];   // Truy vet nguoc lai dinh cha cua end, de tim duong di len tren
        }
        path.push_back(start);             // Cuoi cung them dinh goc vao vector path
        reverse(path.begin(), path.end()); // Lat nguoc lai vector path, ta co duong di tu start toi end
        for (int x : path)
        {
            cout << x << " ";
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
        int n, m, start, end;
        cin >> n >> m >> start >> end;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].insert(y);
        }
        FindPath(start, end);
        cout << endl;
    }
}