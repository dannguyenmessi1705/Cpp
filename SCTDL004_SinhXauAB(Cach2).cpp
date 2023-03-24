// Sinh xau AB
#include <bits/stdc++.h>
using namespace std;
void GenBit(int n, int count, string s)
{
    if (count == n)
    {
        cout << s << " ";
        return;
    }
    GenBit(n, count + 1, s + "A");
    GenBit(n, count + 1, s + "B");
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        GenBit(n, 0, "");
        cout << endl;
    }
}