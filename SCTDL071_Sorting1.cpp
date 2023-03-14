#include <bits/stdc++.h>
using namespace std;
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
    cout << endl;
}
void Sort(int *a, int *b, int n)
{
    int mid;
    if (n & 1)
        mid = n / 2;
    else
        mid = n / 2 + 1;
    for (int i = 0, j = 0, k = 0; i < n; i++)
    {
        if (i & 1)
        {
            b[i] = a[n - j++ - 1];
        }
        else
        {
            b[i] = a[k++];
        }
    }
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int a[1000], b[1000], n;
        cin >> n;
        In(a, n);
        sort(a, a + n, greater<int>());
        Sort(a, b, n);
        Out(b, n);
    }
}