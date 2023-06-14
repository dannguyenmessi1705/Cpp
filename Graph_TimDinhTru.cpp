#include <bits/stdc++.h>
using namespace std;
int n, m;            // Khai bao so dihh so canh
set<int> adj[10001]; // Khao bao mang danh sach ke
bool visted[10001];
void Input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
}
void DFS(int V)
{
    visted[V] = true;
    for (int U : adj[V])
    {
        if (!visted[U])
            DFS(U);
    }
}
// Ham dem so tplt
int DemTPLT()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visted[i])
        {
            cnt++;
            DFS(i);
        }
    }
    return cnt;
}
void Find()
{
    vector<int> dinhtru;
    int dinh = 0;
    memset(visted, false, sizeof visted);
    int tplt = DemTPLT();
    // Bay gio thu loai bo bat ky 1 dinh, neu sau khi loai bo dinh ma lam tang tplt => dinh do la dinh tru
    for (int i = 1; i <= n; i++)
    {
        memset(visted, false, sizeof visted);
        visted[i] = true; // Khi loai bo dinh i, de Ko the xet dinh nay nua ta phai coi nhu no da duoc tham
        int tplt2 = DemTPLT();
        if (tplt < tplt2)
        {                         // Neu so tplt sau khi loai bo dinh khac nhau
            dinhtru.push_back(i); // Do chinh la dinh tru, them vao vector dinh tru
            dinh++;
        }
    }
    cout << "So dinh tru la: " << dinh << endl;
    cout << "Cac dinh la: ";
    for (int x : dinhtru)
    {
        cout << x << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Find();
}
/*
Input:
10 6
5 4
5 2
10 2
10 7
5 3
10 1
*/