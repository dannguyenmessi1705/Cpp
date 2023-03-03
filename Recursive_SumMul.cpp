#include <bits/stdc++.h>
using namespace std;
int Sum(int a[], int n)
{
    if (n <= 0)
    {
        return 0;
    }
    return a[n - 1] + Sum(a, n - 1);
}
long long Mul(int a[], int n)
{
    if (n <= 0)
    {
        return 1;
    }
    return a[n - 1] * Mul(a, n - 1);
}
void In(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    In(a, n);
    cout << "SUM: " << Sum(a, n);
    cout << "\nMUL: " << Mul(a, n);
    delete[] a;
}