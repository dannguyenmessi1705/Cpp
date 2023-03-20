// LA BAI BIENDOIDAYSO1 :))
#include <bits/stdc++.h>
using namespace std;
void In(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void SumOfTwo(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        a[i] = a[i] + a[i + 1];
    }
}
void Out(int a[], int n)
{
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i < n - 1)
            cout << " ";
    }
    cout << "]";
}
void CreateTri(int a[], int n)
{
    while (n > 0)
    {
        Out(a, n);
        SumOfTwo(a, n);
        n--;
        cout << endl;
    }
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int A[100], n;
        cin >> n;
        In(A, n);
        CreateTri(A, n);
    }
}