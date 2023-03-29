/*
Cho mang A[], B[] dau ci N phan tu. Nhiem vu cua ban la tim gia tri nho nhat cua bieu thuc
P = A[0]*B[0] + A[1]*B[1] + ..+A[N-1]*B[N-1]
bang cach trao doi vi tri cc phantu cua cac mang A[] v B[].
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void In(ll *a, ll *b, int n)
{
    int in = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
}
ll Cal(ll *a, ll *b, int n)
{
    ll result = 0;
    for (int i = 0; i < n; i++)
    {
        result += a[i] * b[i];
    }
    return result;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        ll a[n], b[n];
        In(a, b, n);
        sort(a, a + n);
        sort(b, b + n, greater<int>());
        cout << Cal(a, b, n);
        cout << endl;
    }
}