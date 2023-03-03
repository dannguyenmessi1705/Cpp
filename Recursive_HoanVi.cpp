#include <bits/stdc++.h>
using namespace std;
void Out(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void Permutation(int pivot, int a[], int n)
{
    if (pivot == n)
    {
        Out(a, n);
    }
    else
    {
        for (int i = pivot; i <= n; i++)
        {
            swap(a[pivot], a[i]);
            Permutation(pivot + 1, a, n);
            swap(a[pivot], a[i]);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    Permutation(1, a, n);
    delete[] a;
}