#include <bits/stdc++.h>
using namespace std;
int Find(int a[], int n, int x, int pos)
{
    if (x == a[pos])
        return pos;
    if (pos == n)
        return -1;
    return Find(a, n, x, pos + 1);
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
    if (Find(a, n, x, 0) == -1)
    {
        cout << "Khong tim duoc vi tri";
    }
    else
        cout << Find(a, n, x, 0);
    delete[] a;
}
