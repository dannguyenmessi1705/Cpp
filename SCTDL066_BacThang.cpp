/*
Mot chiec cau thang có N bac. Moi buoc, bsn duoc phép buoc lên trên toi da K buoc. Hoi có tat cabao nhiêu cách buoc de di het cau thang? (Tong so buoc dúng bang N).
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int FindWay(int N, int K)
{
    int f[N + 1];
    memset(f, 0, sizeof f); // Set cho tat ca cac cach de buoc len bac F = 0
    f[0] = 1;               // Khoi tao bac o duoi dat co gia tri la 1
    // Vi so buoc trong 1 lan buoc la K <= N nen tai bac thu n F[n] = tong so buoc len cac bac thu F[n-1], F[n-2], F[n-K]... (s/c n-i >= K)
    // VD: Can buoc len bac N = 4, voi moi lan buoc la K = 2 bac
    // De nhay len bac 4 thi ta chi co the buoc tu bac (4-1)=3(can buoc 1 buoc 1 buoc de len bac n) va (4-2)=2(can buoc 1 buoc de len bac n) >= K(2) len
    // Vi the so cach buoc len bac 4 se bang tong so cach buoc len bac 2 + so cach buoc len bac 3
    // => xay dung tu buoc 1 len buoc n
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (i >= j)
            {
                f[i] = (f[i] + f[i - j]) % MOD;
            }
        }
    }
    return f[N];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--)
    {
        int n, k;
        cin >> n >> k;
        cout << FindWay(n, k) << endl;
    }
}
