#include <bits/stdc++.h>
using namespace std;

void Out(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}
// Ham chuyen phan tu lon nhat ve cac nut goc
void heapify(int a[], int n, int i)
{
    int largest = i;   // Gan chi so nut goc i la phan tu co gia tri lon nhat
    int l = 2 * i + 1; // nut trai = 2*i + 1
    int r = 2 * i + 2; // nut phai = 2*i + 2

    // Neu nut con trai lon hon nut goc
    if (l < n && a[l] > a[largest])
        largest = l;

    // Neu nut con phai lon hon nut goc
    if (r < n && a[r] > a[largest])
        largest = r;

    // Neu maxHeap tim duoc ko o nut goc, doi lai vi tri nut goc lam maxheap
    if (largest != i)
    {
        swap(a[i], a[largest]);

        // De quy den cac nut con nho hon
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    // Sap xep, thuc hien heapify (doi voi cac phan tu ko phai nut la, bat dau tu chi so (n/2)-1 ve 0)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // Sau khi heapify tat ca cac nut, thuc hien doi cho maxHeap voi chi so cuoi cung
    for (int i = n - 1; i >= 0; i--)
    {
        // Chuyen maxHeap ve cuoi mang
        swap(a[0], a[i]);

        // Tiep tuc thuc hien heapify de tim ra cac maxHeap
        heapify(a, i, 0);
        Out(a, n);
    }
}

int main()
{
    int n;
    cout << "Nhap so luong phan tu: n = ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    cout << "Mang sau khi sap xep tang dan: ";
    heapSort(a, n);
}
