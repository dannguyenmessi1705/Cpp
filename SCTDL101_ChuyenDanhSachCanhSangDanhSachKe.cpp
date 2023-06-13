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
        set<int> Ke[V + 5];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;   // nhap canh u,v
            Ke[u].insert(v); // them v vao vector u
            Ke[v].insert(u); // thêm u vào vector v
        }

        for (int u = 1; u <= V; u++)
        {
            cout << u << ": ";
            for (int v : Ke[u])
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }
}
