#include <bits/stdc++.h>
using namespace std;
#define MAX 101
char S[MAX];
bool check = true;
void Init()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        S[i] = 'A';
    }
}
void Next_bits()
{
    int i = strlen(S) - 1;
    while (i >= 0 && S[i] != 'A')
    {
        S[i] = 'A';
        i--;
    }
    if (i >= 0)
    {
        S[i] = 'B';
    }
    else
    {
        check = false;
    }
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        check = true;
        Init();
        while (check)
        {
            cout << S << " ";
            Next_bits();
        }
        cout << endl;
    }
}