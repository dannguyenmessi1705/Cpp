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
        int V, E; // Dinh, Canh
        cin >> V >> E;
        vector<vector<int>> Ke(V + 1);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;      // nhap canh u,v
            Ke[u].push_back(v); // them v vao vector u
            Ke[v].push_back(u); // thêm u vào vector v
        }
        // Sap xep cac vector con
        for (int i = 1; i <= V; i++)
        {
            sort(Ke[i].begin(), Ke[i].end());
        }

        for (int u = 1; u <= V; u++)
        {
            cout << u << ": ";
            for (int v = 0; v < Ke[u].size(); v++)
            {
                cout << Ke[u][v] << " ";
            }
            cout << endl;
        }
    }
}
