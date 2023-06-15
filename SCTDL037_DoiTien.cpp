#include <iostream>
using namespace std;
int a[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
int main()
{
    int n = 10, x, test;
    cin >> test;
    while (test--)
    {
        cin >> x;
        long long cnt = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            cnt += x / a[i];
            x %= a[i];
        }
        cout << cnt << endl;
    }
    return 0;
}