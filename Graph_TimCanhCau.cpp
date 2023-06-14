#include <bits/stdc++.h>
using namespace std;
int n, m;                    // Khai bao so dinh, so canh
set<int> adj[10001];         // Khai bao 1 danh sach ke
vector<pair<int, int>> edge; // Khai bao 1 danh sach canh
bool visited[10001];         // Khai bao 1 mang kiem tra cac dinh da tham hay chua
void Nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        edge.push_back({x, y});
    }
}
void DFS(int V)
{
    visited[V] = true;
    for (int U : adj[V])
    {
        if (!visited[U])
            DFS(U);
    }
}

int DemTPLT()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            DFS(i);
        }
    }
    return cnt;
}

// Chay DFS voi dieu kien bo canh tao boi dinh S va F
void DFS2(int V, int S, int F)
{
    visited[V] = true;
    for (int U : adj[V])
    {
        if ((V == S && U == F) || (V == F && U == S)) // Neu xet vao canh tao boi 2 dinh S va F, ta ko duyet ma xet tiep
            continue;
        if (!visited[U])
            DFS2(U, S, F);
    }
}

void Find()
{
    int canhcau = 0;
    vector<pair<int, int>> canh;
    memset(visited, false, sizeof visited);
    int tplt = DemTPLT();
    for (auto i : edge)
    {
        memset(visited, false, sizeof visited);
        int S = i.first;
        int F = i.second;
        int tplt2 = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j])
            {
                tplt2++;
                DFS2(j, S, F);
            }
        }
        if (tplt2 > tplt)
        {
            canhcau++;
            canh.push_back(i);
        }
    }
    cout << "So canh cau la: " << canhcau << endl;
    for (auto i : canh)
    {
        cout << i.first << " " << i.second << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Nhap();
    Find();
}
/*
Input:
10 8
10 9
10 8
10 3
10 4
5 3
10 1
5 1
5 4
*/