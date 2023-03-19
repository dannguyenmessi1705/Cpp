#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll n, k;
// Khai bao struct Ma Tran de co the tra ve ket qua khi thuc hien cac phep tinh
struct Matrix
{
    ll matrix[20][20]{}; // Khai bao MT 20x20 vs gia tri 0
};
// Lam 1 toan tu '*' giua 2 struct
Matrix operator*(Matrix a, Matrix b)
{
    Matrix result;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < n; l++)
            {
                result.matrix[i][j] = (result.matrix[i][j] + (a.matrix[i][l] * b.matrix[l][j]) % MOD) % MOD;
            }
        }
    }
    return result;
};
// Ham tinh nhanh luy thua, su dung CT truy hoi
Matrix Pow(Matrix a, ll k)
{
    if (k == 1)
        return a;
    Matrix result = Pow(a, k / 2);
    if (k & 1)
    {
        return a * result * result;
    }
    return result * result;
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        Matrix a;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a.matrix[i][j];
            }
        }
        a = Pow(a, k);
        ll cross_matrix = 0;
        // Phep tinh duong cheo chinh cua MT
        for (int i = 0; i < n; i++)
        {
            cross_matrix += a.matrix[i][i];
            cross_matrix %= MOD;
        }
        cout << cross_matrix << endl;
    }
}