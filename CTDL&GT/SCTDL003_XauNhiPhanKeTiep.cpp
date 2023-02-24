// Bai lam tuong tu voi bai SCTDL001
// Bai nay phai dung Char :)) String ko AC :))
#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
char X[MAX];
void Next_Bits(char X[])
{
    int n = strlen(X);
    int i = n - 1;
    while (i >= 0 && X[i] != '0')
    {
        X[i] = '0';
        i--;
    }
    if (i >= 0)
    {
        X[i] = '1';
    }
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        cin >> X;
        Next_Bits(X);
        cout << X << endl;
    }
}