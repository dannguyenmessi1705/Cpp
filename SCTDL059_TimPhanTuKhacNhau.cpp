/*
Cho hai mang da duoc sap xep A[] và B[] gom N và N-1 phan tu. Cac phan tu cua mang A[] chi khac mang B[] mot phan tu duy nhat. Hay tim vi tri cua phan tu khac nhau giua A[] và B[].
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void In(ll *x, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> i[x];
    }
}
// Tim bang Tim kiem nhi phan
int FindPos(ll *a, ll *b, int left, int right)
{
    if (left >= right)
        return left;

    int mid = left + (right - left) / 2;
    if (a[mid] == b[mid])
    {
        FindPos(a, b, mid + 1, right);
    }
    else if (a[mid] != b[mid])
    {
        FindPos(a, b, left, mid);
    }
}
// Duyet chay => Cach nay lai dung :))
int FindPos1(ll *a, ll *b, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            return i;
        }
    }
    return n;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        ll a[n], b[n - 1];
        In(a, n);
        In(b, n - 1);
        cout << FindPos1(a, b, n - 1) + 1 << endl;
    }
}