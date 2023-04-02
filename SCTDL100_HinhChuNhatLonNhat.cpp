#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while (test--)
    {
        int N;
        cin >> N;
        int a[N]{}, right[N]{}, left[N]{}, st[N]{};
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
            st[i] = a[i]; // Sao chep mang a sang st de lam mang check cac bien gioi
        }
        // Xet bien gioi ben phai tu phan tu N-2 ve 0, right[N-1] = 0 (Gia tri cuoi thi ko con bien phai nua);
        for (int i = N - 2; i >= 0; i--)
        {
            int j = i + 1;                    // Tao bien j de check cac day bien ben phai tu phan tu dang xet
            int max = 0;                      // Dem so kha nang co the mo rong dien tich
            while (j != N && a[i] <= st[j++]) // Neu phan tu dang xet nho hon bien phai
                max++;
            right[i] = max; // So cot co the mo rong o ben phai cua phan tu i
        }
        // Xet bien gioi ben trai tu phan tu 1 toi N, left[0] = 0 (Gia tri dau thi ko con bien trai nua);
        for (int i = 1; i < N; i++)
        {
            int j = i - 1;                // Tao bien j de check cac day bien ben trai tu phan tu dang xet
            int max = 0;                  // Dem so cot co the mo rong dien tich
            while (~j && a[i] <= st[j--]) // Neu phan tu dang xet nho hon bien trai
                max++;
            left[i] = max; // So cot co the mo rong o ben phai cua phan tu i
        }
        ll area = -1;
        // Tim dien tich lon nhat cua cac cot co the mo rong dien tich
        for (int i = 0; i < N; i++)
        {
            area = max(area, 1LL * (right[i] + left[i] + 1) * a[i]); //(S = (so cot co the mo rong ben trai
                                                                     // + so cot co the mo rong ben phai + 1)
                                                                     // * chieu cao )
        }
        cout << area << endl;
    }
}