#include <bits/stdc++.h>
using namespace std;
long long Sum(int a[], int n)
{
    if (n <= 0)
    {
        return 0;
    }
    return a[n - 1] + Sum(a, n - 1);
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
    cout << Sum(a, n);
    delete[] a;
}