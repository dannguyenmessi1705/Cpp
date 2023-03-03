#include <bits/stdc++.h>
using namespace std;
int FindMax(int a[], int n)
{
    if (n == 1)
    {
        return a[0];
    }
    return max(a[n - 1], FindMax(a, n - 1));
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
    cout << "Max of Array is: " << FindMax(a, n);
    delete[] a;
}