#include <bits/stdc++.h>

using namespace std;

void In(pair<int, int> *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
}

int BinarySearch(pair<int, int> *a, int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int middle = (low + high) / 2;

        if (a[middle].first == x)
            return a[middle].second;

        else if (x > a[middle].first)
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
    cin >> n;
    pair<int, int> *a;
    In(a, n);
    cin >> x;
    sort(a, a + n);
    int result = BinarySearch(a, n, x);
    cout << "vi tri " << result;
}
