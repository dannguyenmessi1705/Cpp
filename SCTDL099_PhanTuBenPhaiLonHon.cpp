#include <bits/stdc++.h>
using namespace std;
void In(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        int a[n]{}, kq[n]{};
        In(a, n);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= a[i]) // Neu stack chua rong hoac chua tim duoc phan tu => pop de loai dan
                s.pop();
            kq[i] = s.empty() ? -1 : s.top(); // Neu stack rong => ko co phan tu nao
            s.push(a[i]);                     // push a[i] vao stack de xet tiep
        }
        for (auto i : kq)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}