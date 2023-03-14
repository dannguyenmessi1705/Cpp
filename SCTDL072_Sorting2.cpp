#include <iostream>
#include <cmath>
using namespace std;

int n, x, *a, *b;

int swap(int &a, int &b)
{
    int x = a;
    a = b;
    b = x;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        cin >> x;
        a = new int[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        b = new int[n + 1];
        for (int i = 1; i <= n; i++)
        {
            b[i] = abs(x - a[i]);
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (b[i] > b[j])
                    swap(b[i], b[j]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << b[i] << " ";
        }
    }
}