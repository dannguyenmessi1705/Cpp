#include <bits/stdc++.h>
using namespace std;
bool visited[10001];
vector<int> adj[10001]; // Khoi tao danh sach ke
void BFS(int V)
{
    queue<int> q;      // Khoi tao queue chua cac dinh
    q.push(V);         // Dua dinh V vao queue
    visited[V] = true; // Danh dau dinh V da duoc tham
    while (!q.empty())
    {                      // Neu q chua rong, ta xet, tim cac dinh theo chieu rong
        int U = q.front(); // Lay dinh ma vao dau tien trong queue ra
        q.pop();           // Sau khi lay xong dong thoi xoa no di
        cout << U << " ";
        for (int x : adj[U])
        { // Duyet cac dinh ke voi U
            if (!visited[x])
            {                      // Neu dinh x chua duoc tham
                q.push(x);         // Them x vao queue
                visited[x] = true; // Sau khi them x vao queue danh dau x da duoc tham
            }
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
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        memset(visited, false, sizeof visited);
        BFS(start);
        cout << endl;
    }
}