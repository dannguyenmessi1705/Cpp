#include <bits/stdc++.h>
using namespace std;
int Sum(int k)
{
    if (k == 0)
        return 0;
    return ((k % 10) + Sum(k / 10));
}
int main()
{
    int k;
    cin >> k;
    cout << Sum(k);
}