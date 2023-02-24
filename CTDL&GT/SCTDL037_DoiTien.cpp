#include <iostream>
using namespace std;
int a[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
int l[100001], b[100001];
int moneyChange(int b[], int x)
{

    for (int i = 0; i <= x; i++)
        l[i] = 0;
    for (int i = 0; i < 10; i++)
        l[b[i]] = 1;
    for (int i = 1; i <= x; i++)
        for (int j = 0; j < 10; j++)
            if (i >= b[j])
            {
                if ((l[i] > l[i - b[j]] + 1 && l[i - b[j]] != 0) || (l[i] == 0 && l[i - b[j]] != 0))
                {
                    l[i] = l[i - b[j]] + 1;
                }
            }
    return l[x];
}
int main()
{
    int n, x, test;
    cin >> test;
    while (test--)
    {
        for (int i = 0; i < 10; i++)
            b[i] = a[i];
        cin >> x;
        cout << moneyChange(b, x) << endl;
    }
    return 0;
}