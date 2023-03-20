// TREN WEB LAPTRINH.PTIT.EDU.VN BI LOI TESTCASE SANG BAI SORTING1 !!!

/*
Cho mang A[] gom n phan tu và so X. Hay dua sap xep cac phan tu cua mang theo tri tuyet doi cua |X - A[i] |. Vi du voi A[] = {10, 5, 3, 9, 2} và X = 7 ta dua ra mang duoc sap xep theo nguyen tac ke tren: A[] = {5, 9, 10, 3, 2} vi |7-10|=3, |7-5|=2, |7-3|=4, |7-9|=2, |7-2|=5.

*/

#include <bits/stdc++.h>
using namespace std;

// Khai bao 1 struct luu gia tri, Tri tuyet doi cua X-data, va vi tri cua no
struct Array
{
    int data;
    int pos;
    int subabs;
};
// bool Compare(Array a, Array b)
// {

//     if (a.subabs > b.subabs)
//         return false;
//     if (a.subabs == b.subabs && a.pos > b.pos)
//         return false;
//     return true; // Dung dieu kien thi thuc hien swap(sort)
// }

void Compare(Array a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].subabs > a[j].subabs)
                swap(a[i], a[j]);
            else if (a[i].subabs == a[j].subabs && a[i].pos > a[j].pos)
            {
                swap(a[i], a[j]);
            }
            else
                continue;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--)
    {
        int n, X;
        cin >> n >> X;
        Array a[n] = {};
        for (int i = 0; i < n; i++)
        {
            a[i].pos = i;
            cin >> a[i].data;
            a[i].subabs = abs(X - a[i].data);
        }
        // sort(a, a + n, Compare);
        Compare(a, n);
        for (Array i : a)
        {
            cout << i.data << " ";
        }
        cout << endl;
    }
}