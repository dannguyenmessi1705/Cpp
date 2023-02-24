#include <bits/stdc++.h>
using namespace std;
void Reverse(int a[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    else
    {
        swap(a[start], a[end]);
    }
    return Reverse(a, start + 1, end - 1);
}
void In(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void Out(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    In(a, n);
    Reverse(a, 0, n - 1);
    Out(a, n);
    delete a;
}