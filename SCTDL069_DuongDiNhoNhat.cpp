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
        int N, M;
        cin >> N >> M;
        int dp[N + 1][M + 1]{}, A[N + 1][M + 1]{};
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                cin >> A[i][j];
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (i == 1 && j == 1)
                    dp[i][j] = A[i][j]; // Khoi tao diem dau cua MT kq = A(1, 1)
                else if (i == 1)
                    dp[i][j] = A[i][j] + dp[i][j - 1]; //  Khoi tao hang 1 cua MT kq = gia tri do dai tu diem (1,1)
                                                       // toi cac diem sau trong hang
                else if (j == 1)
                    dp[i][j] = A[i][j] + dp[i - 1][j]; // Khoi tao cot 1 cua MT kq = gia tri do dai tu diem (1,1)
                                                       // toi cac diem sau trong cot
                else
                    // Gan gia tri diem thu (i,j) cua MT Kq = min cua cac diem o truoc luc den no
                    // sau do cong cho chinh gia tri tai diem (i, j) cua MT dau
                    dp[i][j] = A[i][j] + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
            }
        }
        cout << dp[N][M]; // Tra ve kq co gia tri min trong MT KQ
        cout << endl;
    }
}