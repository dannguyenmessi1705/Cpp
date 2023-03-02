#include <bits/stdc++.h>
using namespace std;
string Gray(string Binary)
{
    string gray = "";
    gray += Binary[0];
    for (int i = 1; i < Binary.length(); i++)
    {
        gray += (Binary[i - 1] != Binary[i]) ? "1" : "0";
    }
    return gray;
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string Binary;
        cin >> Binary;
        cout << Gray(Binary);
        cout << endl;
    }
}