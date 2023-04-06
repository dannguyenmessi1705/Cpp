#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int M;
    cin >> M;
    int a[M + 5][M + 5]{};
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < M; i++)
    {
        cout << i + 1 << ": ";
        for (int j = 0; j < M; j++)
        {
            if (a[i][j] == 1)
            {
                cout << j + 1 << " ";
            }
        }
        cout << "\n";
    }
}
