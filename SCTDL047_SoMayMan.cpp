/*
Hoàng yêu thích các so may man. Ta biet rang mot so là so may man neu bieu dien thap phân cua nó chi chua các chu so may man là 4 và 7.
Ví du, các so 47, 744, 4 là so may man và 5, 17, 467 không phai.
Hoàng muon tìm so may man bé nhat có tong các chu so bang n. Hãy giúp anh ay
*/
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
        int N;
        cin >> N;
        int an4 = 0, an7 = 0;
        for (int i = N; i >= 0; i--)
        {
            if (N >= 4 * i && (N - 4 * i) % 7 == 0)
            {
                an4 = i;
                an7 = (N - 4 * i) / 7;
            }
        }
        if (4 * an4 + 7 * an7 == N)
        {
            for (int i = 1; i <= an4; i++)
            {
                cout << 4;
            }
            for (int i = 1; i <= an7; i++)
            {
                cout << 7;
            }
        }
        else
        {
            cout << -1;
        }
        cout << endl;
    }
}