// Sắp xếp tăng dần
#include <iostream>
using namespace std;
void Nhap(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void Xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void Sapxep(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int value = a[i + 1];
        int index = i + 1;
        while (index > 0 && a[index - 1] > value)
        {
            a[index] = a[index - 1];
            index--;
        }
        a[index] = value;
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    Nhap(a, n);
    Sapxep(a, n);
    Xuat(a, n);
}