#include <bits/stdc++.h>
using namespace std;
bool visited[10001];
int parent[10001];
vector<int> adj[10001];
void BFS(int V)
{
    queue<int> q;      // Khoi tao queue chua cac dinh
    q.push(V);         // Dua dinh V vao queue
    visited[V] = true; // Danh dau dinh V da duoc tham
    while (!q.empty())
    {                      // Neu q chua rong, ta xet, tim cac dinh theo chieu rong
        int U = q.front(); // Lay dinh ma vao dau tien trong queue ra
        q.pop();           // Sau khi lay xong dong thoi xoa no di
        for (int x : adj[U])
        { // Duyet cac dinh ke voi U
            if (!visited[x])
            {                      // Neu dinh x chua duoc tham
                q.push(x);         // Them x vao queue
                visited[x] = true; // Sau khi them x vao queue danh dau x da duoc tham
                parent[x] = U;     // Them dinh cha U cho dinh con X vao mang parent
            }
        }
    }
}
void FindPath(int start, int end)
{
    memset(visited, false, sizeof visited);
    memset(parent, 0, sizeof parent);
    BFS(start);
    if (!visited[end])
    {
        cout << "Do thi khong lien thong, start khong the toi duoc end";
    }
    else
    {
        // Truy vet tu diem cuoi ve diem dau
        vector<int> path; // Khoi tao vector chi duong
        while (end != start)
        {                        // Neu diem cuoi chua di ve toi diem dau
            path.push_back(end); // Them dinh end vao duong di
            end = parent[end];   // Truy vet lai dinh cha cua dinh end
        }
        path.push_back(start);             // them dinh dau vao duong di
        reverse(path.begin(), path.end()); // Dao nguoc lai duong di
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
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        FindPath(start, end);
        cout << endl;
    }
}