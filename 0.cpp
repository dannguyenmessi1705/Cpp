#include <bits/stdc++.h>
using namespace std;
int MT[10001][10001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    memset(MT, 0, sizeof(MT));
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        MT[x][y] = 1;
        MT[y][x] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << MT[i][j] << " ";
        }
        cout << endl;
    }
}
