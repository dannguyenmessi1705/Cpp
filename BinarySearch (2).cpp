#include <bits/stdc++.h>

using namespace std;
void In(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void Out(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int BinarySearch(int a[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int middle = (low + high) / 2;

        if (a[middle] == x)
            return middle;

        else if (x > a[middle])
            low = middle + 1;
        else
            high = middle - 1;
    }
    // Tra ve -1 neu khong thay gia tri trong mang
    return -1;
}
int main()
{
    int n, x;
    cout << "Nhap so n: ";
    cin >> n;
    int a[n];
    cout << "Nhap day: ";
    In(a, n);
    sort(a, a + n);
    cout << "Day so duoc sap xep la: ";
    Out(a, n);
    cout << "\nNhap so x can tim: ";
    cin >> x;
    int result = BinarySearch(a, n, x);
    result != -1 ? cout << "Vi tri: " << result : cout << "Khong tim duoc vi tri";
}
